//
// BAGEL - Parallel electron correlation program.
// Filename: box.cc
// Copyright (C) 2016 Toru Shiozaki
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


#include <src/util/f77.h>
#include <src/periodic/box.h>
#include <src/periodic/multipolebatch.h>
#include <src/integral/os/overlapbatch.h>
#include <src/periodic/localexpansion.h>

using namespace bagel;
using namespace std;

static const double pisq__ = pi__ * pi__;

void Box::init() {

  centre_ = {{0, 0, 0}};
  nbasis0_ = 0;   nbasis1_ = 0;
  for (auto& i : sp_) {
    centre_[0] += i->centre(0);
    centre_[1] += i->centre(1);
    centre_[2] += i->centre(2);
    nbasis0_ += i->nbasis0();
    nbasis1_ += i->nbasis1();
  }
  centre_[0] /= nsp();
  centre_[1] /= nsp();
  centre_[2] /= nsp();

  extent_ = 0;
  for (auto& i : sp_) {
    if (i->schwarz() < 1e-15) continue;
    double tmp = 0;
    for (int j = 0; j != 3; ++j)
      tmp += pow(i->centre(j)-centre_[j], 2.0);
    const double ei = sqrt(tmp) + i->extent();
    assert(ei > 0);
    if (extent_ < ei) extent_ = ei;
  }
}


void Box::insert_sp(vector<shared_ptr<const ShellPair>> sp) {

  const int nsp = sp_.size();
  sp_.resize(nsp + sp.size());
  for (int i = 0; i != sp.size(); ++i)
    sp_[i + nsp] = sp[i];

}


void Box::insert_child(shared_ptr<const Box> child) {

  const int nchild = child_.size();
  if (child) {
    child_.resize(nchild + 1);
    child_[nchild] = child;
  }
}


void Box::get_neigh(vector<shared_ptr<Box>> box, const int ws) {

  neigh_.resize(box.size());
  int nn = 0;
  for (auto& b : box) {
    if (b->rank() == rank_ && is_neigh(b, ws)) {
      neigh_[nn] = b;
      ++nn;
    }
  }
  neigh_.resize(nn);
}


bool Box::is_neigh(shared_ptr<const Box> box, const int ws) const {

  double rr = 0;
  for (int i = 0; i != 3; ++i)
    rr += pow(centre_[i] - box->centre(i), 2);

  const bool out = (sqrt(rr) < (1+ws)*(extent_ + box->extent()));
  return out;
}


void Box::get_inter(vector<shared_ptr<Box>> box, const int ws) {

  inter_.resize(box.size());
  int ni = 0;
  for (auto& b : box) {
    if (b->rank() == rank_ && !is_neigh(b, ws) && (!parent_ || parent_->is_neigh(b->parent(), ws))) {
      inter_[ni] = b;
      ++ni;
    }
  }
  inter_.resize(ni);
}


void Box::compute_multipoles() {

  const int nmult = (lmax_ + 1) * (lmax_ + 1);

  multipole_.resize(nmult);
  vector<shared_ptr<ZMatrix>> multipole(nmult);
  for (int i = 0; i != nmult; ++i)
    multipole[i] = make_shared<ZMatrix>(nbasis1_, nbasis0_);

  if (nchild() == 0) { // leaf = shift sp's multipoles
    size_t offset0 = 0;
    size_t offset1 = 0;
    for (auto& v : sp_) {
      array<double, 3> r12;
      r12[0] = centre_[0] - v->centre(0);
      r12[1] = centre_[1] - v->centre(1);
      r12[2] = centre_[2] - v->centre(2);
      LocalExpansion shift(r12, v->multipoles(), lmax_);
      vector<shared_ptr<const ZMatrix>> moment = shift.compute_shifted_multipoles();

      for (int i = 0; i != nmult; ++i)
        multipole[i]->copy_block(offset1, offset0, v->nbasis1(), v->nbasis0(), moment[i]->data());

      offset0 += v->nbasis0();
      offset1 += v->nbasis1();
    }
    assert(offset0 == nbasis0_);
    assert(offset1 == nbasis1_);
  } else { // shift children's multipoles
    size_t offset0 = 0;
    size_t offset1 = 0;
    for (int n = 0; n != nchild(); ++n) {
      shared_ptr<const Box> c = child(n);
      array<double, 3> r12;
      r12[0] = centre_[0] - c->centre(0);
      r12[1] = centre_[1] - c->centre(1);
      r12[2] = centre_[2] - c->centre(2);
      LocalExpansion shift(r12, c->multipole(), lmax_);
      vector<shared_ptr<const ZMatrix>> moment = shift.compute_shifted_multipoles();

      for (int i = 0; i != nmult; ++i)
        multipole[i]->copy_block(offset1, offset0, c->nbasis1(), c->nbasis0(), moment[i]->data());

      offset0 += c->nbasis0();
      offset1 += c->nbasis1();
    }
    assert(offset0 == nbasis0_);
    assert(offset1 == nbasis1_);
  }

  for (int i = 0; i != nmult; ++i)
    multipole_[i] = multipole[i];
}
