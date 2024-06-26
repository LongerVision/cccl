//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <cuda/std/chrono>

// system_clock

// static time_point now();

#include <cuda/std/cassert>
#include <cuda/std/chrono>

int main(int, char**)
{
  typedef cuda::std::chrono::system_clock C;
  C::time_point t1 = C::now();
  assert(t1.time_since_epoch().count() != 0);
  assert(C::time_point::min() < t1);
  assert(C::time_point::max() > t1);

  return 0;
}
