//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads, pre-sm-60
// UNSUPPORTED: windows && pre-sm-70

// <cuda/std/atomic>

// void atomic_signal_fence(memory_order m);

#include <cuda/std/atomic>

#include "test_macros.h"

int main(int, char**)
{
  cuda::std::atomic_signal_fence(cuda::std::memory_order_seq_cst);

  return 0;
}
