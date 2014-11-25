//
// BAGEL - Parallel electron correlation program.
// Filename: pfock.cc
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Hai-Anh Le <anh@u.northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// The BAGEL package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the BAGEL package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//


#include <src/periodic/pfock.h>

using namespace std;
using namespace bagel;

BOOST_CLASS_EXPORT_IMPLEMENT(PFock)

PFock::PFock(const shared_ptr<const Lattice> l, shared_ptr<const PData> h, const shared_ptr<const PData> density)
  : PData(l->primitive_cell()->nbasis(), l->num_lattice_vectors()), lattice_(l), previous_(h), pdensity_(density) {

  assert(h->blocksize() == blocksize_ && density->blocksize() == blocksize_);
  assert(h->nblock() == nblock_ && density->nblock() == nblock_);
  zero();
  form_pfock();
}

void PFock::form_pfock() {

  // 1e part
  for (int i = 0; i != nblock_; ++i)
    *(pdata_[i]) += *((*previous_)(i));

  // Coulomb term
  Timer time;
  shared_ptr<const PDFDist> df = lattice_->df();

  shared_ptr<PData> jop = df->pcompute_Jop(pdensity_);
  for (int i = 0; i != nblock_; ++i)
    *(pdata_[i]) += *((*jop)(i));

  time.tick_print("Coulomb build in PFock");
}
