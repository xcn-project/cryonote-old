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
#include <map>
#include "cryptonote_basic_impl.hpp"

namespace cryptonote
{
  class checkpoints
  {
  public:
    checkpoints();
    bool add_checkpoint(uint64_t height, const std::string& hash_str);
    bool is_in_checkpoint_zone(uint64_t height) const;
    bool is_height_passed_zone(uint64_t height, uint64_t blockchain_last_block_height) const;
    uint64_t get_top_checkpoint_height() const;
    bool check_block(uint64_t height, const crypto::hash& h) const;
    bool check_block(uint64_t height, const crypto::hash& h, bool& is_a_checkpoint) const;
    bool is_alternative_block_allowed(uint64_t blockchain_height, uint64_t block_height) const;

  private:
    std::map<uint64_t, crypto::hash> m_points;
  };
}
