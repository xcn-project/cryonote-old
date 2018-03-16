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

#include "net/http_client.h"
#include "cryptonote_protocol/blobdatatype.h"
#include "simpleminer_protocol_defs.h"

namespace mining
{
  class  simpleminer
  {
  public:
    static void init_options(boost::program_options::options_description& desc);
    bool init(const boost::program_options::variables_map& vm);
    bool run();
  private:
    struct job_details_native
    {
      cryptonote::blobdata blob;
      uint32_t target;
      std::string job_id;
    };

    static bool text_job_details_to_native_job_details(const job_details& job, job_details_native& native_details);

    std::string m_pool_ip;
    std::string m_pool_port;
    std::string m_login;
    std::string m_pass;
    int m_cryptonight_dark;
    epee::net_utils::http::http_simple_client m_http_client;
  };
}
