//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: inline.h
// Copyright (C) 2009 Quantum Simulation Technologies, Inc.
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


#ifndef __src_rysint_inline_h
#define __src_rysint_inline_h

#include <cassert>
#include <src/util/math/algo.h>

namespace bagel {
namespace {

double inline_erf(const double inpt) {
  constexpr std::array<std::array<double,13>,5> a {{
  std::array<double,13>{{
    0.00000000005958930743, -0.00000000113739022964, 0.00000001466005199839, -0.00000016350354461960,
    0.00000164610044809620, -0.00001492559551950604, 0.00012055331122299265, -0.00085483269811296660,
    0.00522397762482322257, -0.02686617064507733420, 0.11283791670954881569, -0.37612638903183748117,
    1.12837916709551257377
  }}, {{
    0.00000000002372510631, -0.00000000045493253732, 0.00000000590362766598, -0.00000006642090827576,
    0.00000067595634268133, -0.00000621188515924000, 0.00005103883009709690, -0.00037015410692956173,
    0.00233307631218880978, -0.01254988477182192210, 0.05657061146827041994, -0.21379664776456006580,
    0.84270079294971486929
  }}, {{
    0.00000000000949905026, -0.00000000018310229805, 0.00000000239463074000, -0.00000002721444369609,
    0.00000028045522331686, -0.00000261830022482897, 0.00002195455056768781, -0.00016358986921372656,
    0.00107052153564110318, -0.00608284718113590151, 0.02986978465246258244, -0.13055593046562267625,
    0.67493323603965504676
  }}, {{
    0.00000000000382722073, -0.00000000007421598602, 0.00000000097930574080, -0.00000001126008898854,
    0.00000011775134830784, -0.00000111992758382650, 0.00000962023443095201, -0.00007404402135070773,
    0.00050689993654144881, -0.00307553051439272889, 0.01668977892553165586, -0.08548534594781312114,
    0.56909076642393639985
  }}, {{
    0.00000000000155296588, -0.00000000003032205868, 0.00000000040424830707, -0.00000000471135111493,
    0.00000005011915876293, -0.00000048722516178974, 0.00000430683284629395, -0.00003445026145385764,
    0.00024879276133931664, -0.00162940941748079288, 0.00988786373932350462, -0.05962426839442303805,
    0.49766113250947636708
  }} }};
  constexpr std::array<std::array<double,13>,5> b {{
  {{
    -0.00000000029734388465,  0.00000000269776334046, -0.00000000640788827665, -0.00000001667820132100,
    -0.00000021854388148686,  0.00000266246030457984,  0.00001612722157047886, -0.00025616361025506629,
     0.00015380842432375365,  0.00815533022524927908, -0.01402283663896319337, -0.19746892495383021487,
     0.71511720328842845913
  }}, {{
    -0.00000000001951073787, -0.00000000032302692214,  0.00000000522461866919,  0.00000000342940918551,
    -0.00000035772874310272,  0.00000019999935792654,  0.00002687044575042908, -0.00011843240273775776,
    -0.00080991728956032271,  0.00661062970502241174,  0.00909530922354827295, -0.20160072778491013140,
     0.51169696718727644908
  }}, {{
     0.00000000003147682272, -0.00000000048465972408,  0.00000000063675740242,  0.00000003377623323271,
    -0.00000015451139637086, -0.00000203340624738438,  0.00001947204525295057,  0.00002854147231653228,
    -0.00101565063152200272,  0.00271187003520095655,  0.02328095035422810727, -0.16725021123116877197,
     0.32490054966649436974
  }}, {{
     0.00000000002319363370, -0.00000000006303206648, -0.00000000264888267434,  0.00000002050708040581,
     0.00000011371857327578, -0.00000211211337219663,  0.00000368797328322935,  0.00009823686253424796,
    -0.00065860243990455368, -0.00075285814895230877,  0.02585434424202960464, -0.11637092784486193258,
     0.18267336775296612024
  }}, {{
    -0.00000000000367789363,  0.00000000020876046746, -0.00000000193319027226, -0.00000000435953392472,
     0.00000018006992266137, -0.00000078441223763969, -0.00000675407647949153,  0.00008428418334440096,
    -0.00017604388937031815, -0.00239729611435071610,  0.02064129023876022970, -0.06905562880005864105,
     0.09084526782065478489
  }} }};

  double t = inpt;
  assert(t >= 0.0);
  if (t < 2.2) {
    t *= t;
    const int k = static_cast<int>(t);
    t -= k;
    t = detail::taylor_expansion<13>(t, a[k]) *inpt;
  } else if (t < 6.9) {
    const int k = static_cast<int>(t);
    t -= k;
    t = detail::taylor_expansion<13>(t, b[k-2]);
    t *= t;
    t *= t;
    t *= t;
    t = 1.0 - t * t;
  } else {
    t = 1.0;
  }
  return t;
}


double inline_dawson(double xx) {
  // based on the rational approximation - see details in Moshier, Methods and Programs for Mathematical Functions, Prentice-Hall, 1989.
  constexpr std::array<double, 10> num0 {{
    1.13681498971755972054e-11, 8.49262267667473811108e-10, 1.94434204175553054283e-8, 9.53151741254484363489e-7, 3.07828309874913200438e-6,
    3.52513368520288738649e-4, -8.50149846724410912031e-4,  4.22618223005546594270e-2,-9.17480371773452345351e-2, 9.99999999999999994612e-1
  }};
  constexpr std::array<double, 11> num1 {{
    5.08955156417900903354e-1, -2.44754418142697847934e-1, 9.41512335303534411857e-2, -2.18711255142039025206e-2, 3.66207612329569181322e-3,
    -4.23209114460388756528e-4, 3.59641304793896631888e-5, -2.14640351719968974225e-6, 9.10010780076391431042e-8, -2.40274520828250956942e-9, 3.59233385440928410398e-11
  }};
  constexpr std::array<double, 5> num2 {{
    -5.90592860534773254987e-1, 6.29235242724368800674e-1, -1.72858975380388136411e-1, 1.64837047825189632310e-2, -4.86827613020462700845e-4
  }};
  constexpr std::array<double, 11> denom0 {{
    2.40372073066762605484e-11, 1.48864681368493396752e-9, 5.21265281010541664570e-8, 1.27258478273186970203e-6, 2.32490249820789513991e-5,
    3.25524741826057911661e-4, 3.48805814657162590916e-3, 2.79448531198828973716e-2, 1.58874241960120565368e-1, 5.74918629489320327824e-1, 1.00000000000000000539e0
  }};
  constexpr std::array<double, 11> denom1 {{
    1.00000000000000000000e0, -6.31839869873368190192e-1, 2.36706788228248691528e-1, -5.31806367003223277662e-2, 8.48041718586295374409e-3,
    -9.47996768486665330168e-4, 7.81025592944552338085e-5, -4.55875153252442634831e-6, 1.89100358111421846170e-7, -4.91324691331920606875e-9, 7.18466403235734541950e-11
  }};
  constexpr std::array<double, 6> denom2 {{
    1.00000000000000000000e0, -2.69820057197544900361e0, 1.73270799045947845857e0, -3.93708582281939493482e-1, 3.44278924041233391079e-2, -9.73655226040941223894e-4
  }};

  const int sign = xx < 0 ? -1 : 1;
  const double x = std::fabs(xx);
  if (x < 3.25) {
    const double x2 = x*x;
    const double an = detail::taylor_expansion<10>(x2, num0);
    const double ad = detail::taylor_expansion<11>(x2, denom0);
    return sign*x*an/ad;
  } else if (x < 6.25) {
    const double x2 = 1.0/(x*x);
    const double an = detail::taylor_expansion<11>(x2, num1);
    const double ad = detail::taylor_expansion<11>(x2, denom1);
    return sign*0.5*(1.0/x+x2*an/(ad*x));
  } else if (x < 1.0e9) {
    const double x2 = 1.0/(x*x);
    const double an = detail::taylor_expansion<5>(x2, num2);
    const double ad = detail::taylor_expansion<6>(x2, denom2);
    return sign*0.5*(1.0/x+x2*an/(ad*x));
  } else {
    return sign*0.5/x;
  }
}

}
}

#endif
