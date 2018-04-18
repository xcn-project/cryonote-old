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

#pragma once

#include "crypto/crypto.h"
#include "cryptonote_core/cryptonote_basic.h"

class test_cn_slow_hash
{
public:
  static const size_t loop_count = 10;

#pragma pack(push, 1)
  struct data_t
  {
    char data[13];
  };
#pragma pack(pop)

  static_assert(13 == sizeof(data_t), "Invalid structure size");

  bool init()
  {
    if (!epee::string_tools::hex_to_pod("63617665617420656d70746f72", m_data))
      return false;

    if (!epee::string_tools::hex_to_pod("bbec2cacf69866a8e740380fe7b818fc78f8571221742d729d9d02d7f8989b87", m_expected_hash))
      return false;

    if (!epee::string_tools::hex_to_pod("98c48cda9ab5d26ef2717e7375f665fc18b703aac6c059bb814685f21946647f", m_expected_hash_dark))
      return false;


    return true;
  }

  bool test()
  {
    crypto::hash hash;
    crypto::hash hash_dark;

    crypto::cn_slow_hash(&m_data, sizeof(m_data), hash, 0);
    crypto::cn_slow_hash(&m_data, sizeof(m_data), hash_dark, 1);
    return (hash == m_expected_hash) && (hash_dark == m_expected_hash_dark);
  }

private:
  data_t m_data;
  crypto::hash m_expected_hash;
  crypto::hash m_expected_hash_dark;
};
