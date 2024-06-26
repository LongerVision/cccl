//===----------------------------------------------------------------------===//
//
// Part of libcu++, the C++ Standard Library for your entire system,
// under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//
// <memory>

// unique_ptr

// Test unique_ptr move assignment

#include <cuda/std/__memory_>
#include <cuda/std/cassert>

#include "test_macros.h"
#include "unique_ptr_test_helper.h"

// test assignment from null
template <bool IsArray>
__host__ __device__ TEST_CONSTEXPR_CXX23 void test_basic()
{
  typedef typename cuda::std::conditional<IsArray, A[], A>::type VT;
  const int expect_alive = IsArray ? 5 : 1;
  {
    cuda::std::unique_ptr<VT> s2(newValue<VT>(expect_alive));
    if (!TEST_IS_CONSTANT_EVALUATED_CXX23())
    {
      assert(A_count == expect_alive);
    }
    s2 = NULL;
    if (!TEST_IS_CONSTANT_EVALUATED_CXX23())
    {
      assert(A_count == 0);
    }
    assert(s2.get() == 0);
  }
  if (!TEST_IS_CONSTANT_EVALUATED_CXX23())
  {
    assert(A_count == 0);
  }
}

__host__ __device__ TEST_CONSTEXPR_CXX23 bool test()
{
  test_basic</*IsArray*/ false>();
  test_basic<true>();

  return true;
}

int main(int, char**)
{
  test();
#if TEST_STD_VER >= 2023
  static_assert(test());
#endif // TEST_STD_VER >= 2023

  return 0;
}
