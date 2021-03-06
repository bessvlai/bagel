//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: goverlapbatch.h
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


#ifndef __SRC_INTEGRAL_OS_GOVERLAPBATCH_H
#define __SRC_INTEGRAL_OS_GOVERLAPBATCH_H

#include <src/integral/os/osintegral.h>

namespace bagel {

class GOverlapBatch : public OSInt {
  protected:
    int nblocks() const override { return 6; }
    int nrank() const override { return 1; }

  public:
    GOverlapBatch(const std::array<std::shared_ptr<const Shell>,2>& o) : OSInt(o) { common_init(); }

    void compute();

};

class GDerivOverBatch : public OSInt {
  protected:
    int nblocks() const override { return 6; }
    int nrank() const override { return 1; }

  public:
    GDerivOverBatch(const std::array<std::shared_ptr<const Shell>,2>& o) : OSInt(o) { common_init(); }

    void compute();

};

}

#endif
