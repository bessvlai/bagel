//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: dfpcmo.cc
// Copyright (C) 2018 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
//
// This file is part of the BAGEL package.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <fstream>
#include <iomanip>
#include <src/util/parallel/mpi_interface.h>
#include <src/util/io/dfpcmo.h>

using namespace std;
using namespace bagel;

DFPCMO::DFPCMO(shared_ptr<const ZMatrix> c, shared_ptr<const VectorB> e, double en, int ne, int np, int nb)
 : coeff_(c), eig_(e), energy_(en), nesol_(ne), npsol_(np), nbasis_(nb) {

}


void DFPCMO::print() const {
  if (mpi__->rank() == 0) { 
    assert(mpi__->depth() == 0);

    stringstream ss;
    ss << "Caution!! This file has been generated by BAGEL" << endl;
    ss << " " << 1 << " " << nesol_ << " " << npsol_ << " " << nbasis_ << endl;
    ss << setprecision(16) << setw(24) << scientific << energy_ << endl;

    // coefficient blocks
    ss << setprecision(16) << fixed;
    for (size_t i = 0; i < coeff_->size(); i += 3) {
      for (size_t j = 0; j != min(3ul, coeff_->size()-i); ++j)
        ss << setw(44) << coeff_->element((i+j)%coeff_->ndim(), (i+j)/coeff_->ndim());
      ss << endl;
    }

    // Fock eigenvalues
    ss << setprecision(12) << scientific;
    for (size_t i = 0; i < eig_->size(); i += 6) {
      for (size_t j = 0; j != min(6ul, eig_->size()-i); ++j)
        ss << setw(22) << (*eig_)[i+j];
      ss << endl;
    }

    // for consistency (supersymmetry info)
    for (size_t i = 0; i < nesol_ + npsol_; i += 66) {
      for (size_t j = 0; j != min(66ul, nesol_+npsol_-i); ++j)
        ss << " " << 1; 
      ss << endl;
    }

    ofstream fs("DFPCMO");
    assert(fs.is_open());
    fs << ss.str();
  }
}
