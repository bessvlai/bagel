//
// BAGEL - Parallel electron correlation program.
// Filename: _gvrr_00b0.cc
// Copyright (C) 2009 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and\/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
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


#include <src/grad/gvrrlist.h>

// returns double array of length 72
void GVRRList::_gvrr_00b0(double* data_, const double* C00, const double* D00, const double* B00, const double* B01, const double* B10) {
#ifdef __GNUC__
  const double C00_[6]__attribute__((aligned(32))) = {C00[0], C00[1], C00[2], C00[3], C00[4], C00[5]};
  const double D00_[6]__attribute__((aligned(32))) = {D00[0], D00[1], D00[2], D00[3], D00[4], D00[5]};
  const double B00_[6]__attribute__((aligned(32))) = {B00[0], B00[1], B00[2], B00[3], B00[4], B00[5]};
  const double B01_[6]__attribute__((aligned(32))) = {B01[0], B01[1], B01[2], B01[3], B01[4], B01[5]};
  const double B10_[6]__attribute__((aligned(32))) = {B10[0], B10[1], B10[2], B10[3], B10[4], B10[5]};
#else
  const double* C00_ = C00;
  const double* D00_ = D00;
  const double* B00_ = B00;
  const double* B01_ = B01;
  const double* B10_ = B10;
#endif

  for (int t = 0; t != 6; ++t)
    data_[0+t] = 1.0;

  for (int t = 0; t != 6; ++t)
    data_[6+t] = D00_[t];

  double B01_current[6];
  for (int t = 0; t != 6; ++t)
    B01_current[t] = B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[12+t] = D00_[t] * data_[6+t] + B01_current[t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[18+t] = D00_[t] * data_[12+t] + B01_current[t] * data_[6+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[24+t] = D00_[t] * data_[18+t] + B01_current[t] * data_[12+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[30+t] = D00_[t] * data_[24+t] + B01_current[t] * data_[18+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[36+t] = D00_[t] * data_[30+t] + B01_current[t] * data_[24+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[42+t] = D00_[t] * data_[36+t] + B01_current[t] * data_[30+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[48+t] = D00_[t] * data_[42+t] + B01_current[t] * data_[36+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[54+t] = D00_[t] * data_[48+t] + B01_current[t] * data_[42+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[60+t] = D00_[t] * data_[54+t] + B01_current[t] * data_[48+t];

  for (int t = 0; t != 6; ++t)
    B01_current[t] += B01_[t];

  for (int t = 0; t != 6; ++t)
    data_[66+t] = D00_[t] * data_[60+t] + B01_current[t] * data_[54+t];
}

