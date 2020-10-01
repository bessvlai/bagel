//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: MRCI_gen15.cc
// Copyright (C) 2014 Quantum Simulation Technologies, Inc.
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

#include <bagel_config.h>
#ifdef COMPILE_SMITH

#include <src/smith/mrci/MRCI_tasks15.h>

using namespace std;
using namespace bagel;
using namespace bagel::SMITH;
using namespace bagel::SMITH::MRCI;

Task700::Task700(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task701::Task701(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task702::Task702(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task703::Task703(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task704::Task704(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task705::Task705(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task706::Task706(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x3 : *range[1])
    for (auto& c3 : *range[0])
      if (t[0]->is_local(c3, x3))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c3, x3}}, in, t[0], range));
}

Task707::Task707(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x3 : *range[1])
    for (auto& c3 : *range[0])
      if (t[0]->is_local(c3, x3))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c3, x3}}, in, t[0], range));
}

Task708::Task708(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task709::Task709(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x3 : *range[1])
    for (auto& c3 : *range[0])
      if (t[0]->is_local(c3, x3))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c3, x3}}, in, t[0], range));
}

Task710::Task710(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x3 : *range[1])
    for (auto& c3 : *range[0])
      if (t[0]->is_local(c3, x3))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c3, x3}}, in, t[0], range));
}

Task711::Task711(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task712::Task712(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock()*range[0]->nblock()*range[0]->nblock());
  for (auto& x1 : *range[1])
    for (auto& c5 : *range[0])
      for (auto& c3 : *range[0])
        for (auto& c1 : *range[0])
          if (t[0]->is_local(c1, c3, c5, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c1, c3, c5, x1}}, in, t[0], range));
}

Task713::Task713(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task714::Task714(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock()*range[0]->nblock()*range[0]->nblock());
  for (auto& x1 : *range[1])
    for (auto& c5 : *range[0])
      for (auto& c3 : *range[0])
        for (auto& c1 : *range[0])
          if (t[0]->is_local(c1, c3, c5, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c1, c3, c5, x1}}, in, t[0], range));
}

Task715::Task715(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task716::Task716(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& a2 : *range[2])
      for (auto& c3 : *range[0])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, c3, a2, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, c3, a2, x1}}, in, t[0], range));
}

Task717::Task717(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[0]->nblock()*range[1]->nblock()*range[2]->nblock());
  for (auto& a2 : *range[2])
    for (auto& c3 : *range[0])
      for (auto& x0 : *range[1])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, x0, c3, a2))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, x0, c3, a2}}, in, t[0], range));
}

Task718::Task718(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task719::Task719(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& a2 : *range[2])
      for (auto& c3 : *range[0])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, c3, a2, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, c3, a2, x1}}, in, t[0], range));
}

Task720::Task720(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[0]->nblock()*range[1]->nblock()*range[2]->nblock());
  for (auto& a2 : *range[2])
    for (auto& c3 : *range[0])
      for (auto& x0 : *range[1])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, x0, c3, a2))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, x0, c3, a2}}, in, t[0], range));
}

Task721::Task721(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task722::Task722(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& a4 : *range[2])
      for (auto& c3 : *range[0])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, c3, a4, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, c3, a4, x1}}, in, t[0], range));
}

Task723::Task723(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[0]->nblock()*range[1]->nblock()*range[2]->nblock());
  for (auto& a4 : *range[2])
    for (auto& c3 : *range[0])
      for (auto& x0 : *range[1])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, x0, c3, a4))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, x0, c3, a4}}, in, t[0], range));
}

Task724::Task724(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[0]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& c3 : *range[0])
    for (auto& a4 : *range[2])
      for (auto& c1 : *range[0])
        for (auto& a2 : *range[2])
          if (t[0]->is_local(a2, c1, a4, c3))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a2, c1, a4, c3}}, in, t[0], range));
}

Task725::Task725(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& a4 : *range[2])
      for (auto& c3 : *range[0])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, c3, a4, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, c3, a4, x1}}, in, t[0], range));
}

Task726::Task726(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[0]->nblock()*range[1]->nblock()*range[2]->nblock());
  for (auto& a4 : *range[2])
    for (auto& c3 : *range[0])
      for (auto& x0 : *range[1])
        for (auto& a5 : *range[2])
          if (t[0]->is_local(a5, x0, c3, a4))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a5, x0, c3, a4}}, in, t[0], range));
}

Task727::Task727(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[2]->nblock()*range[0]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& a3 : *range[2])
        for (auto& c2 : *range[0])
          if (t[0]->is_local(c2, a3, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c2, a3, x0, a1}}, in, t[0], range));
}

Task728::Task728(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task729::Task729(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x0 : *range[1])
    for (auto& x1 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x1, x0))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x1, x0}}, in, t[0], range));
}

Task730::Task730(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,1> in = {{t[1]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock()*range[2]->nblock()*range[1]->nblock());
  for (auto& x2 : *range[1])
    for (auto& c2 : *range[0])
      for (auto& a3 : *range[2])
        for (auto& x3 : *range[1])
          if (t[0]->is_local(x3, a3, c2, x2))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{x3, a3, c2, x2}}, in, t[0], range));
}

Task731::Task731(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task732::Task732(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a1 : *range[2])
          if (t[0]->is_local(a1, c2, x0, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a1, c2, x0, x1}}, in, t[0], range));
}

Task733::Task733(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& x1 : *range[1])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a1 : *range[2])
          if (t[0]->is_local(a1, c2, x0, x1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a1, c2, x0, x1}}, in, t[0], range));
}

Task734::Task734(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task735::Task735(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock());
  for (auto& x0 : *range[1])
    for (auto& a3 : *range[2])
      if (t[0]->is_local(a3, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{a3, x0}}, in, t[0], range));
}

Task736::Task736(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task737::Task737(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[2]->nblock());
  for (auto& x0 : *range[1])
    for (auto& a1 : *range[2])
      if (t[0]->is_local(a1, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{a1, x0}}, in, t[0], range));
}

Task738::Task738(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task739::Task739(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task740::Task740(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task741::Task741(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task742::Task742(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task743::Task743(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task744::Task744(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task745::Task745(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[1]->nblock()*range[0]->nblock());
  for (auto& x0 : *range[1])
    for (auto& c4 : *range[0])
      if (t[0]->is_local(c4, x0))
        subtasks_.push_back(make_shared<Task_local>(array<const Index,2>{{c4, x0}}, in, t[0], range));
}

Task746::Task746(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[1]->nblock()*range[0]->nblock()*range[2]->nblock());
  for (auto& a1 : *range[2])
    for (auto& x0 : *range[1])
      for (auto& c2 : *range[0])
        for (auto& a3 : *range[2])
          if (t[0]->is_local(a3, c2, x0, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{a3, c2, x0, a1}}, in, t[0], range));
}

Task747::Task747(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[2]->nblock()*range[1]->nblock()*range[0]->nblock());
  for (auto& a1 : *range[2])
    for (auto& a3 : *range[2])
      for (auto& x1 : *range[1])
        for (auto& c2 : *range[0])
          if (t[0]->is_local(c2, x1, a3, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c2, x1, a3, a1}}, in, t[0], range));
}

Task748::Task748(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[2]->nblock()*range[1]->nblock()*range[0]->nblock());
  for (auto& a1 : *range[2])
    for (auto& a3 : *range[2])
      for (auto& x1 : *range[1])
        for (auto& c2 : *range[0])
          if (t[0]->is_local(c2, x1, a3, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c2, x1, a3, a1}}, in, t[0], range));
}

Task749::Task749(vector<shared_ptr<Tensor>> t, array<shared_ptr<const IndexRange>,3> range) {
  array<shared_ptr<const Tensor>,2> in = {{t[1], t[2]}};
  out_ = t[0];
  in_ = in;
  subtasks_.reserve(range[2]->nblock()*range[2]->nblock()*range[1]->nblock()*range[0]->nblock());
  for (auto& a1 : *range[2])
    for (auto& a3 : *range[2])
      for (auto& x1 : *range[1])
        for (auto& c2 : *range[0])
          if (t[0]->is_local(c2, x1, a3, a1))
            subtasks_.push_back(make_shared<Task_local>(array<const Index,4>{{c2, x1, a3, a1}}, in, t[0], range));
}

#endif
