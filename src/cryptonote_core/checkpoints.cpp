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

#include "include_base_utils.h"

using namespace epee;

#include "checkpoints.hpp"

namespace cryptonote
{
  //---------------------------------------------------------------------------
  checkpoints::checkpoints()
  {
  }
  //---------------------------------------------------------------------------
  bool checkpoints::add_checkpoint(uint64_t height, const std::string& hash_str)
  {
    crypto::hash h = null_hash;
    bool r = epee::string_tools::parse_tpod_from_hex_string(hash_str, h);
    CHECK_AND_ASSERT_MES(r, false, "WRONG HASH IN CHECKPOINTS!!!");
    CHECK_AND_ASSERT_MES(m_points.count(height) == 0, false, "WRONG HASH IN CHECKPOINTS!!!");
    m_points[height] = h;
    return true;
  }
  //---------------------------------------------------------------------------
  bool checkpoints::is_in_checkpoint_zone(uint64_t height) const
  {
    return !m_points.empty() && (height <= (--m_points.end())->first);
  }
  //---------------------------------------------------------------------------
  bool checkpoints::is_height_passed_zone(uint64_t height, uint64_t blockchain_last_block_height) const
  {
    if (height > blockchain_last_block_height)
    {
      return false;
    }

    auto it = m_points.lower_bound(height);
    if (it == m_points.end())
    {
      return false;
    }

    if (it->first <= blockchain_last_block_height)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  //---------------------------------------------------------------------------
  uint64_t checkpoints::get_top_checkpoint_height() const
  {
    if (!m_points.size())
    {
      return 0;
    }

    return (--m_points.end())->first;
  }
  //---------------------------------------------------------------------------
  bool checkpoints::check_block(uint64_t height, const crypto::hash& h, bool& is_a_checkpoint) const
  {
    auto it = m_points.find(height);
    is_a_checkpoint = it != m_points.end();
    if (!is_a_checkpoint)
    {
      return true;
    }

    if (it->second == h)
    {
      LOG_PRINT_GREEN("CHECKPOINT PASSED FOR HEIGHT " << height << " " << h, LOG_LEVEL_0);
      return true;
    }
    else
    {
      LOG_ERROR("CHECKPOINT FAILED FOR HEIGHT " << height << ". EXPECTED HASH: " << it->second << ", FETCHED HASH: " << h);
      return false;
    }
  }
  //---------------------------------------------------------------------------
  bool checkpoints::check_block(uint64_t height, const crypto::hash& h) const
  {
    bool ignored;
    return check_block(height, h, ignored);
  }
  //---------------------------------------------------------------------------
  bool checkpoints::is_alternative_block_allowed(uint64_t blockchain_height, uint64_t block_height) const
  {
    if (0 == block_height)
    {
      return false;
    }

    auto it = m_points.upper_bound(blockchain_height);
    // is blockchain_height before the first checkpoint?
    if (it == m_points.begin())
    {
      return true;
    }

    --it;
    uint64_t checkpoint_height = it->first;
    LOG_PRINT_L0("checkpoint height: " << checkpoint_height << ", m_points.size(): " << m_points.size());
    return checkpoint_height < block_height;
  }
}
