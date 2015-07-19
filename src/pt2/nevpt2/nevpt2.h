//
// BAGEL - Parallel electron correlation program.
// Filename: nevpt2.h
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
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


#ifndef __SRC_NEVPT2_NEVPT2_H
#define __SRC_NEVPT2_NEVPT2_H

#include <src/wfn/method.h>
#include <src/df/dfdistt.h>
#include <src/df/reldffullt.h>
#include <src/util/math/quatmatrix.h>
#include <src/wfn/relreference.h>

namespace bagel {

template<typename DataType>
class NEVPT2 : public Method {
  protected:
    using MatType  = typename std::conditional<std::is_same<DataType,double>::value, Matrix, ZMatrix>::type;
    using DiagType = typename std::conditional<std::is_same<DataType,double>::value, Matrix, QuatMatrix>::type;
    using VecType  = typename std::conditional<std::is_same<DataType,double>::value, VectorB, ZVectorB>::type;
    using ViewType = typename std::conditional<std::is_same<DataType,double>::value, MatView, ZMatView>::type;
    using DFType   = typename std::conditional<std::is_same<DataType,double>::value, DFDistT, RelDFFullT>::type;

  protected:
    int ncore_;
    int nclosed_;
    int nact_;
    int nvirt_;
    int istate_;
    double norm_thresh_;

    std::string abasis_;

    double energy_;

    // density matrices to be used
    // particle RDMs
    std::shared_ptr<const MatType> rdm1_;
    std::shared_ptr<const MatType> rdm2_;
    std::shared_ptr<const MatType> rdm3_;
    std::shared_ptr<const MatType> rdm4_;
    // hole RDMs
    std::shared_ptr<const MatType> hrdm1_;
    std::shared_ptr<const MatType> hrdm2_;
    std::shared_ptr<const MatType> hrdm3_;
    // <a+a b+b c+c..>
    std::shared_ptr<const MatType> ardm2_;
    std::shared_ptr<const MatType> ardm3_;
    std::shared_ptr<const MatType> ardm4_;
    // <a+a bb+>
    std::shared_ptr<const MatType> srdm2_;
    // <a+a bb+ c+c>
    std::shared_ptr<const MatType> srdm3_;

    // integrals in physicists notation
    std::shared_ptr<const MatType> ints2_;
    std::shared_ptr<      MatType> fockact_;
    std::shared_ptr<      MatType> fockact_c_;
    std::shared_ptr<      MatType> fockact_h_;
    std::shared_ptr<      MatType> fockact_p_;

    // K and K'mat
    std::shared_ptr<const MatType> qvec_;
    std::shared_ptr<const MatType> kmat_;
    std::shared_ptr<const MatType> kmatp_;
    std::shared_ptr<const MatType> kmat2_;
    std::shared_ptr<const MatType> kmatp2_;

    // A
    std::shared_ptr<const MatType> amat2_;
    std::shared_ptr<const MatType> amat3_;
    std::shared_ptr<const MatType> amat3t_;
    // B
    std::shared_ptr<const MatType> bmat2_;
    std::shared_ptr<const MatType> bmat2t_;
    // C
    std::shared_ptr<const MatType> cmat2_;
    std::shared_ptr<const MatType> cmat2t_;
    // D
    std::shared_ptr<const MatType> dmat2_;
    std::shared_ptr<const MatType> dmat1_;
    std::shared_ptr<const MatType> dmat1t_;

    void init_reference();
    std::shared_ptr<MatType> compute_fock(std::shared_ptr<const Geometry> cgeom, std::shared_ptr<const MatType> hcore,
                                          const ViewType coeff, const double scale_exch = 1.0, const double scale_coulomb = 1.0);
    std::tuple<std::shared_ptr<DFType>,std::shared_ptr<DFType>>
      compute_full_nevpt2(std::shared_ptr<const Geometry>, std::shared_ptr<const MatType>, std::shared_ptr<const MatType>,
                          std::shared_ptr<const MatType>, std::shared_ptr<const MatType>) const;
    void compute_rdm();
    void compute_hrdm();
    void compute_asrdm();
    void compute_ints();
    void compute_kmat();
    void compute_abcd();

    std::shared_ptr<const MatType> coeff() const;
    std::tuple<std::shared_ptr<MatType>,VectorB> remove_core(std::shared_ptr<const MatType> in, const VectorB& eig) const;

  public:
    NEVPT2(std::shared_ptr<const PTree>, std::shared_ptr<const Geometry>, std::shared_ptr<const Reference> = nullptr);

    virtual void compute() override;
    virtual std::shared_ptr<const Reference> conv_to_ref() const override { return ref_; }

    double energy() const { return energy_; }
    int ncore() const { return ncore_; }
    std::string abasis() const { return abasis_; }
};

template<> void NEVPT2<double>::init_reference();
template<> void NEVPT2<std::complex<double>>::init_reference();

template<> void NEVPT2<double>::compute_rdm();
template<> void NEVPT2<std::complex<double>>::compute_rdm();

template<> std::shared_ptr<const Matrix> NEVPT2<double>::coeff() const;
template<> std::shared_ptr<const ZMatrix> NEVPT2<std::complex<double>>::coeff() const;
template<> std::tuple<std::shared_ptr<Matrix>,VectorB> NEVPT2<double>::remove_core(std::shared_ptr<const Matrix>, const VectorB&) const;
template<> std::tuple<std::shared_ptr<ZMatrix>,VectorB> NEVPT2<std::complex<double>>::remove_core(std::shared_ptr<const ZMatrix>, const VectorB&) const;

template<> std::shared_ptr<Matrix> NEVPT2<double>::compute_fock(std::shared_ptr<const Geometry> cgeom, std::shared_ptr<const Matrix> hcore,
                                                                const MatView coeff, const double exch, const double coulomb);
template<> std::shared_ptr<ZMatrix> NEVPT2<std::complex<double>>::compute_fock(std::shared_ptr<const Geometry> cgeom, std::shared_ptr<const ZMatrix> hcore,
                                                                               const ZMatView coeff, const double exch, const double coulomb);

template<> std::tuple<std::shared_ptr<DFDistT>,std::shared_ptr<DFDistT>>
  NEVPT2<double>::compute_full_nevpt2(std::shared_ptr<const Geometry>, std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>,
                                      std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>) const;
template<> std::tuple<std::shared_ptr<RelDFFullT>,std::shared_ptr<RelDFFullT>>
  NEVPT2<std::complex<double>>::compute_full_nevpt2(std::shared_ptr<const Geometry>, std::shared_ptr<const ZMatrix>, std::shared_ptr<const ZMatrix>,
                                                    std::shared_ptr<const ZMatrix>, std::shared_ptr<const ZMatrix>) const;

extern template class NEVPT2<double>;
extern template class NEVPT2<std::complex<double>>;

}

#endif
