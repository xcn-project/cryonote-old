// Copyright (c) 2018, The Bitnote Developers.
// Portions Copyright (c) 2012-2013, The CryptoNote Developers.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "checkpoints.h"
#include "misc_log_ex.h"

#define ADD_CHECKPOINT(height, hash) CHECK_AND_ASSERT(checkpoints.add_checkpoint(height, hash), false);

namespace cryptonote {
  inline bool create_checkpoints(cryptonote::checkpoints& checkpoints)
  {
    ADD_CHECKPOINT(1, "5166c689c723f1a65de71014cc90b6a8c737d1d40f7359fce2e5a5f775a153ac");
    ADD_CHECKPOINT(1000, "655536e51a55e76f79b69a85ab3809a93e7c848798a71cc315c3005ce44570a1");
    ADD_CHECKPOINT(2000, "4904cacd893577f5030b299a1639a7d323a5e0df834cc35a106fad46d1690eab");
    ADD_CHECKPOINT(4000, "8a8c1350efff4dcc8bff1ea228738abbefa43898646dc92504e724d42f95780d");
    ADD_CHECKPOINT(8000, "e4208527001295674f240d3b7ce8db5ea737704a0b68be728566d181b7c9f1a2");
    return true;
  }
}
