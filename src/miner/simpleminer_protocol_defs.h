// Copyright (c) 2018, The Bitnote Developers.
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

#include "cryptonote_protocol/cryptonote_protocol_defs.h"
#include "cryptonote_core/cryptonote_basic.h"
#include "crypto/hash.h"
#include "net/rpc_method_name.h"

namespace mining
{
  //-----------------------------------------------
#define CORE_RPC_STATUS_OK   "OK"


  struct job_details
  {
    std::string blob;
    std::string target;
    std::string job_id;

    BEGIN_KV_SERIALIZE_MAP()
      KV_SERIALIZE(blob)
      KV_SERIALIZE(target)
      KV_SERIALIZE(job_id)
    END_KV_SERIALIZE_MAP()
  };


  struct COMMAND_RPC_LOGIN
  {
    RPC_METHOD_NAME("login");

    struct request
    {
      std::string login;
      std::string pass;
      std::string agent;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(login)
        KV_SERIALIZE(pass)
        KV_SERIALIZE(agent)
      END_KV_SERIALIZE_MAP()
    };


    struct response
    {
      std::string status;
      std::string id;
      job_details job;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(status)
        KV_SERIALIZE(id)
        KV_SERIALIZE(job)
      END_KV_SERIALIZE_MAP()
    };
  };

  struct COMMAND_RPC_GETJOB
  {
    RPC_METHOD_NAME("getjob");

    struct request
    {
      std::string id;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(id)
      END_KV_SERIALIZE_MAP()
    };

    typedef job_details response;
  };

  struct COMMAND_RPC_SUBMITSHARE
  {
    RPC_METHOD_NAME("submit");

    struct request
    {
      std::string id;
      std::string nonce;
      std::string result;
      std::string job_id;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(id)
        KV_SERIALIZE(nonce)
        KV_SERIALIZE(result)
        KV_SERIALIZE(job_id)
      END_KV_SERIALIZE_MAP()
    };

    struct response
    {
      std::string status;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(status)
      END_KV_SERIALIZE_MAP()
    };
  };
}
