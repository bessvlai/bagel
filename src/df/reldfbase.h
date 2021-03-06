//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: reldfbase.h
// Copyright (C) 2012 Quantum Simulation Technologies, Inc.
//
// Author: Toru Shiozaki <shiozaki@qsimulate.com>
// Maintainer: QSimulate
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

#ifndef __SRC_REL_RELDFBASE_H
#define __SRC_REL_RELDFBASE_H

#include <src/util/spinorinfo.h>

namespace bagel {

class RelDFBase {
  protected:
    // l,x,y,z
    std::pair<int, int> cartesian_;
    // X,Y, and coefficients
    std::vector<std::shared_ptr<const SpinorInfo>> basis_;

  public:
    RelDFBase(std::pair<int, int> cartesian) : cartesian_(cartesian) {
    }

    RelDFBase(const RelDFBase& o) : cartesian_(o.cartesian_) {
    }

    std::pair<int, int> cartesian() const { return cartesian_; }
    const std::vector<std::shared_ptr<const SpinorInfo>>& basis() const { return basis_; }

};

}

#endif
