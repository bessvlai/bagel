//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: CASA.h
// Copyright (C) 2014 Shiozaki group
//
// Author: Shiozaki group <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// This program is free software; you can redistribute it and/or modify
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


#ifndef __SRC_SMITH_CASA_H
#define __SRC_SMITH_CASA_H

#include <iostream>
#include <tuple>
#include <iomanip>
#include <src/smith/spinfreebase.h>
#include <src/smith/futuretensor.h>
#include <src/scf/hf/fock.h>
#include <src/util/f77.h>
#include <src/smith/queue.h>
#include <src/smith/smith_info.h>

namespace bagel {
namespace SMITH {
namespace CASA{

class CASA : public SpinFreeMethod<double> {
  protected:
    // these are tensors that are used internally
    std::shared_ptr<Tensor> t2;
    std::shared_ptr<Tensor> r;
    std::shared_ptr<Tensor> s;
    std::shared_ptr<Tensor> n;

    int nstates_;
    std::vector<double> err_;
    std::vector<double> pt2energy_;
    std::shared_ptr<Matrix> heff_;

    std::vector<std::shared_ptr<MultiTensor>> t2all_;
    std::vector<std::shared_ptr<MultiTensor>> rall_;
    std::vector<std::shared_ptr<MultiTensor>> sall_;
    std::vector<std::shared_ptr<MultiTensor>> lall_;

    void diagonal(std::shared_ptr<Tensor> r, std::shared_ptr<const Tensor> t, const bool diagonal) const;

    std::shared_ptr<FutureTensor> Gamma0_();
    std::shared_ptr<FutureTensor> Gamma1_();
    std::shared_ptr<FutureTensor> Gamma2_();
    std::shared_ptr<FutureTensor> Gamma3_();
    std::shared_ptr<FutureTensor> Gamma4_();
    std::shared_ptr<FutureTensor> Gamma5_();
    std::shared_ptr<FutureTensor> Gamma7_();
    std::shared_ptr<FutureTensor> Gamma82_();
    std::shared_ptr<FutureTensor> Gamma83_();
    std::shared_ptr<FutureTensor> Gamma9_();
    std::shared_ptr<FutureTensor> Gamma13_();
    std::shared_ptr<FutureTensor> Gamma15_();
    std::shared_ptr<FutureTensor> Gamma84_();
    std::shared_ptr<FutureTensor> Gamma86_();
    std::shared_ptr<FutureTensor> Gamma24_();
    std::shared_ptr<FutureTensor> Gamma25_();
    std::shared_ptr<FutureTensor> Gamma26_();
    std::shared_ptr<FutureTensor> Gamma28_();
    std::shared_ptr<FutureTensor> Gamma29_();
    std::shared_ptr<FutureTensor> Gamma33_();
    std::shared_ptr<FutureTensor> Gamma100_();
    std::shared_ptr<FutureTensor> Gamma101_();
    std::shared_ptr<FutureTensor> Gamma104_();
    std::shared_ptr<FutureTensor> Gamma105_();
    std::shared_ptr<FutureTensor> Gamma40_();
    std::shared_ptr<FutureTensor> Gamma48_();
    std::shared_ptr<FutureTensor> Gamma49_();
    std::shared_ptr<FutureTensor> Gamma50_();
    std::shared_ptr<FutureTensor> Gamma52_();
    std::shared_ptr<FutureTensor> Gamma88_();
    std::shared_ptr<FutureTensor> Gamma89_();
    std::shared_ptr<FutureTensor> Gamma94_();
    std::shared_ptr<FutureTensor> Gamma96_();
    std::shared_ptr<FutureTensor> Gamma80_();
    std::shared_ptr<FutureTensor> Gamma81_();
    std::shared_ptr<FutureTensor> Gamma90_();
    std::shared_ptr<FutureTensor> Gamma92_();
    std::shared_ptr<FutureTensor> Gamma98_();
    std::shared_ptr<FutureTensor> Gamma99_();
    std::shared_ptr<FutureTensor> Gamma109_();
    std::shared_ptr<Queue> make_residualq(const bool reset = true, const bool diagonal = true);
    std::shared_ptr<Queue> make_sourceq(const bool reset = true, const bool diagonal = true);
    std::shared_ptr<Queue> make_normq(const bool reset = true, const bool diagonal = true);

    std::vector<std::shared_ptr<MultiTensor_<double>>>
      solve_linear(std::vector<std::shared_ptr<MultiTensor_<double>>> s, std::vector<std::shared_ptr<MultiTensor_<double>>> t);

  public:
    CASA(std::shared_ptr<const SMITH_Info<double>> ref);
    ~CASA() {}

    void solve();
    void solve_deriv();

    double accumulate(std::shared_ptr<Queue> queue) {
      double sum = 0.0;
      while (!queue->done())
        sum += queue->next_compute()->target();
      mpi__->allreduce(&sum, 1);
      return sum;
    }

};

}
}
}
#endif

