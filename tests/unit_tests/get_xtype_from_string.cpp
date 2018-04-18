// Copyright (c) 2018, The CryoNote Developers.
// Portions Copyright (c) 2012-2013, The CryptoNote Developers.
//
// All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "gtest/gtest.h"

#include <string_tools.h>

using namespace epee::string_tools;

namespace
{
  template<typename T>
  void do_pos_test(T expected, const std::string& str)
  {
    T val;
    ASSERT_TRUE(get_xtype_from_string(val, str));
    ASSERT_EQ(expected, val);
  }

  template<typename T>
  void do_neg_test(const std::string& str)
  {
    T val;
    ASSERT_FALSE(get_xtype_from_string(val, str));
  }
}

#define TEST_pos(int_type, expected, str)                                \
  TEST(get_xtype_from_string, handles_pos_ ## int_type ## _ ## expected) \
  {                                                                      \
    do_pos_test<int_type>(expected, str);                                \
  }

#define DO_MAKE_NEG_TEST_NAME(prefix, int_type, ln) prefix ## int_type ## _ ## ln
#define MAKE_NEG_TEST_NAME(prefix, int_type, ln) DO_MAKE_NEG_TEST_NAME(prefix, int_type, ln)

#define TEST_neg(int_type, str)                                                    \
  TEST(get_xtype_from_string, MAKE_NEG_TEST_NAME(handles_neg, int_type, __LINE__)) \
  {                                                                                \
    do_neg_test<int_type>(str);                                                    \
  }

TEST_pos(uint16_t,     0,     "0");
TEST_pos(uint16_t,     1,     "1");
TEST_pos(uint16_t, 65535, "65535");

TEST_neg(uint16_t, "");
TEST_neg(uint16_t, "+0");
TEST_neg(uint16_t, "+1");
TEST_neg(uint16_t, "+65535");
TEST_neg(uint16_t, "+65536");

TEST_neg(uint16_t, "-0");
TEST_neg(uint16_t, "-1");
TEST_neg(uint16_t, "-65535");
TEST_neg(uint16_t, "-65536");

TEST_neg(uint16_t, ".0");
TEST_neg(uint16_t, ".1");
TEST_neg(uint16_t, "0.0");
TEST_neg(uint16_t, "0.1");
TEST_neg(uint16_t, "1.0");
TEST_neg(uint16_t, "1.1");

TEST_neg(uint16_t, "w");
TEST_neg(uint16_t, "0w");
TEST_neg(uint16_t, "1w");
TEST_neg(uint16_t, "1w1");
TEST_neg(uint16_t, "65535w");

TEST_neg(uint16_t, "65536");
TEST_neg(uint16_t, "4294967296");
TEST_neg(uint16_t, "18446744073709551616");


TEST_pos(uint32_t,          0,          "0");
TEST_pos(uint32_t,          1,          "1");
TEST_pos(uint32_t, 4294967295, "4294967295");

TEST_neg(uint32_t, "");
TEST_neg(uint32_t, "+0");
TEST_neg(uint32_t, "+1");
TEST_neg(uint32_t, "+4294967295");
TEST_neg(uint32_t, "+4294967296");

TEST_neg(uint32_t, "-0");
TEST_neg(uint32_t, "-1");
TEST_neg(uint32_t, "-4294967295");
TEST_neg(uint32_t, "-4294967296");

TEST_neg(uint32_t, ".0");
TEST_neg(uint32_t, ".1");
TEST_neg(uint32_t, "0.0");
TEST_neg(uint32_t, "0.1");
TEST_neg(uint32_t, "1.0");
TEST_neg(uint32_t, "1.1");

TEST_neg(uint32_t, "w");
TEST_neg(uint32_t, "0w");
TEST_neg(uint32_t, "1w");
TEST_neg(uint32_t, "1w1");
TEST_neg(uint32_t, "4294967295w");

TEST_neg(uint32_t, "4294967296");
TEST_neg(uint32_t, "18446744073709551616");

TEST_pos(uint64_t, 0, "0");
TEST_pos(uint64_t, 1, "1");
TEST_pos(uint64_t, 18446744073709551615ULL, "18446744073709551615");

TEST_neg(uint64_t, "");
TEST_neg(uint64_t, "+0");
TEST_neg(uint64_t, "+1");
TEST_neg(uint64_t, "+18446744073709551615");
TEST_neg(uint64_t, "+18446744073709551616");

TEST_neg(uint64_t, "-0");
TEST_neg(uint64_t, "-1");
TEST_neg(uint64_t, "-18446744073709551615");
TEST_neg(uint64_t, "-18446744073709551616");

TEST_neg(uint64_t, ".0");
TEST_neg(uint64_t, ".1");
TEST_neg(uint64_t, "0.0");
TEST_neg(uint64_t, "0.1");
TEST_neg(uint64_t, "1.0");
TEST_neg(uint64_t, "1.1");

TEST_neg(uint64_t, "w");
TEST_neg(uint64_t, "0w");
TEST_neg(uint64_t, "1w");
TEST_neg(uint64_t, "1w1");
TEST_neg(uint64_t, "18446744073709551615w");

TEST_neg(uint64_t, "18446744073709551616");
