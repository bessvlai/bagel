//
// BAGEL - Parallel electron correlation program.
// Filename: bitutil.h
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

#ifndef __SRC_CIUTIL_BITUTIL_H
#define __SRC_CIUTIL_BITUTIL_H

#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <src/util/constants.h>

namespace bagel {
  namespace {

    std::string print_bit(std::bitset<nbit__> bit1, std::bitset<nbit__> bit2, const int nmax) {
      std::string out;
      for (int i = 0; i != nmax; ++i) {
        if (bit1[i] && bit2[i]) { out += "2"; }
        else if (bit1[i]) { out += "a"; }
        else if (bit2[i]) { out += "b"; }
        else { out += "."; }
      }
      return out;
    }

    std::string print_bit(std::bitset<nbit__> bit, const int nmax) {
      std::string out;
      for (int i = 0; i != nmax; ++i) { out += bit[i] ? "1" : "."; }
      return out;
    }

    std::vector<int> bit_to_numbers(std::bitset<nbit__> bit) {
      std::vector<int> out;
      for (int i = 0; i != nbit__; ++i) if (bit[i]) out.push_back(i);
      return out;
    }

    std::bitset<nbit__> numbers_to_bit(const std::vector<int>& num) {
      std::bitset<nbit__> out(0);
      for (auto& i : num) out.set(i);
      return out;
    }

    int sign(std::bitset<nbit__> bit, int i, int j) {
      // masking irrelevant bits
      int min, max;
      std::tie(min,max) = std::minmax(i,j);
      bit &= ((~std::bitset<nbit__>(0ull)) << min+1);
      bit &= ((~std::bitset<nbit__>(0ull)) >> (nbit__ - max));
      return 1 - ((bit.count() & 1) << 1);
    }

    int sign(std::bitset<nbit__> bit, int i) {
      bit &= ((~std::bitset<nbit__>(0ull)) >> (nbit__ - i));
      return 1 - ((bit.count() & 1 ) << 1);
    }

  }
}

#endif
