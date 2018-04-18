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

#include <vector>

#include "cryptonote_core/account.hpp"
#include "cryptonote_core/cryptonote_basic.h"
#include "cryptonote_core/cryptonote_format_utils.hpp"
#include "crypto/crypto.h"

template<size_t a_ring_size>
class multi_tx_test_base
{
  static_assert(0 < a_ring_size, "ring_size must be greater than 0");

public:
  static const size_t ring_size = a_ring_size;
  static const size_t real_source_idx = ring_size / 2;

  bool init()
  {
    using namespace cryptonote;

    std::vector<tx_source_entry::output_entry> output_entries;
    for (size_t i = 0; i < ring_size; ++i)
    {
      m_miners[i].generate();

      if (!construct_miner_tx(0, 0, 0, 2, 0, m_miners[i].get_keys().m_account_address, m_miner_txs[i]))
        return false;

      txout_to_key tx_out = boost::get<txout_to_key>(m_miner_txs[i].vout[0].target);
      output_entries.push_back(std::make_pair(i, tx_out.key));
      m_public_keys[i] = tx_out.key;
      m_public_key_ptrs[i] = &m_public_keys[i];
    }

    m_source_amount = m_miner_txs[0].vout[0].amount;

    tx_source_entry source_entry;
    source_entry.amount = m_source_amount;
    source_entry.real_out_tx_key = get_tx_pub_key_from_extra(m_miner_txs[real_source_idx]);
    source_entry.real_output_in_tx_index = 0;
    source_entry.outputs.swap(output_entries);
    source_entry.real_output = real_source_idx;

    m_sources.push_back(source_entry);

    return true;
  }

protected:
  cryptonote::account_base m_miners[ring_size];
  cryptonote::transaction m_miner_txs[ring_size];
  uint64_t m_source_amount;

  std::vector<cryptonote::tx_source_entry> m_sources;
  crypto::public_key m_public_keys[ring_size];
  const crypto::public_key* m_public_key_ptrs[ring_size];
};
