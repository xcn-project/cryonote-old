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

#include <boost/program_options.hpp>
#include <atomic>
#include "cryptonote_basic.h"
#include "difficulty.hpp"
#include "math_helper.h"

namespace cryptonote
{

  struct i_miner_handler
  {
    virtual bool handle_block_found(block& b) = 0;
    virtual bool get_block_template(block& b, const account_public_address& adr, difficulty_type& diffic, uint64_t& height, const blobdata& ex_nonce) = 0;
  protected:
    ~i_miner_handler(){};
  };

  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
  class miner
  {
  public:
    miner(i_miner_handler* phandler);
    ~miner();
    bool init(const boost::program_options::variables_map& vm);
    static void init_options(boost::program_options::options_description& desc);
    bool set_block_template(const block& bl, const difficulty_type& diffic, uint64_t height);
    bool on_block_chain_update();
    bool start(const account_public_address& adr, size_t threads_count, const boost::thread::attributes& attrs);
    uint64_t get_speed();
    void send_stop_signal();
    bool stop();
    bool is_mining();
    bool on_idle();
    void on_synchronized();
    //synchronous analog (for fast calls)
    static bool find_nonce_for_given_block(block& bl, const difficulty_type& diffic, uint64_t height);
    void pause();
    void resume();
    void do_print_hashrate(bool do_hr);

  private:
    bool worker_thread();
    bool request_block_template();
    void  merge_hr();

    struct miner_config
    {
      uint64_t current_extra_message_index;

      BEGIN_KV_SERIALIZE_MAP()
        KV_SERIALIZE(current_extra_message_index)
      END_KV_SERIALIZE_MAP()
    };


    volatile uint32_t m_stop;
    epee::critical_section m_template_lock;
    block m_template;
    std::atomic<uint32_t> m_template_no;
    std::atomic<uint32_t> m_starter_nonce;
    difficulty_type m_diffic;
    uint64_t m_height;
    volatile uint32_t m_thread_index;
    volatile uint32_t m_threads_total;
    std::atomic<int32_t> m_pausers_count;
    epee::critical_section m_miners_count_lock;

    std::list<boost::thread> m_threads;
    epee::critical_section m_threads_lock;
    i_miner_handler* m_phandler;
    account_public_address m_mine_address;
    epee::math_helper::once_a_time_seconds<5> m_update_block_template_interval;
    epee::math_helper::once_a_time_seconds<2> m_update_merge_hr_interval;
    std::vector<blobdata> m_extra_messages;
    miner_config m_config;
    std::string m_config_folder_path;
    std::atomic<uint64_t> m_last_hr_merge_time;
    std::atomic<uint64_t> m_hashes;
    std::atomic<uint64_t> m_current_hash_rate;
    epee::critical_section m_last_hash_rates_lock;
    std::list<uint64_t> m_last_hash_rates;
    bool m_do_print_hashrate;
    bool m_do_mining;

  };
}
