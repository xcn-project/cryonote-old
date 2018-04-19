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

#include "misc_log_ex.h"

#include "checkpoints.hpp"

#define ADD_CHECKPOINT(height, hash) CHECK_AND_ASSERT(checkpoints.add_checkpoint(height, hash), false);

namespace cryptonote
{
  inline bool create_checkpoints(cryptonote::checkpoints& checkpoints)
  {
    // CryptoNight
    ADD_CHECKPOINT(1, "5166c689c723f1a65de71014cc90b6a8c737d1d40f7359fce2e5a5f775a153ac");
    ADD_CHECKPOINT(1000, "655536e51a55e76f79b69a85ab3809a93e7c848798a71cc315c3005ce44570a1");
    ADD_CHECKPOINT(2000, "4904cacd893577f5030b299a1639a7d323a5e0df834cc35a106fad46d1690eab");
    ADD_CHECKPOINT(4000, "8a8c1350efff4dcc8bff1ea228738abbefa43898646dc92504e724d42f95780d");
    ADD_CHECKPOINT(8000, "e4208527001295674f240d3b7ce8db5ea737704a0b68be728566d181b7c9f1a2");
    ADD_CHECKPOINT(16000, "1050b1f8415a0c5be54cc587dbddbef523376468f5c265742294fafc6e962fb1");

    // CryptoNight - PoW Exceptions
    ADD_CHECKPOINT(17630, "5a6f9b07c858baa20e9374dc76cba4fe4decd9e0648a998a430738e4f22d8699");
    ADD_CHECKPOINT(18090, "27b6be4d66646ef0b0ed2973c118a98d4d47401ee6da535be47680fe1a7a810c");
    ADD_CHECKPOINT(18912, "23e9e60cd1be249d3b56c082d0839eb7f23546e5cb7576f69ede649a4b30b022");

    // CryptoNight Dark
    ADD_CHECKPOINT(30100, "105d5651d1c705573cd187096a7be1e968896e410ffa78f27d0e77d5e95ae79e");

    return true;
  }
}
