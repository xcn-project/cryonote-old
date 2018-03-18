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

#define CRYPTONOTE_MAX_BLOCK_NUMBER                          500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                            500000000
#define CRYPTONOTE_MAX_TX_SIZE                               1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER               0
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX              1
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW                 10
#define CRYPTONOTE_CURRENT_TRANSACTION_VERSION               1
#define CRYPTONOTE_CURRENT_BLOCK_MAJOR_VERSION               1
#define CRYPTONOTE_CURRENT_BLOCK_MINOR_VERSION               0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT                   60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE                  10
#define CRYPTONOTE_HARDFORK_HEIGHT_1                         100
#define CRYPTONOTE_BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW         15

#define MONEY_SUPPLY                                         ((uint64_t)1200000000000000)
#define EMISSION_SPEED_FACTOR                                18

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                      100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE            300000
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE               600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                     8

#define COIN                                                 ((uint64_t)100000000)
#define DEFAULT_FEE                                          ((uint64_t)1000000)

#define CRYPTONOTE_DIFFICULTY_TARGET                         30
#define CRYPTONOTE_DIFFICULTY_WINDOW                         360
#define CRYPTONOTE_DIFFICULTY_WINDOW_V2                      CRYPTONOTE_DIFFICULTY_WINDOW / 2
#define CRYPTONOTE_DIFFICULTY_LAG                            5
#define CRYPTONOTE_DIFFICULTY_CUT                            25
#define CRYPTONOTE_DIFFICULTY_BLOCKS_COUNT                   CRYPTONOTE_DIFFICULTY_WINDOW + CRYPTONOTE_DIFFICULTY_LAG

#define CRYPTONOTE_MIN_TX_MIXIN_SIZE                         0

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS           CRYPTONOTE_DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS            1
#define CRYPTONOTE_UPPER_TX_SIZE_LIMIT                       CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 14 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE

#define CRYPTONOTE_DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN       CRYPTONOTE_DIFFICULTY_TARGET

#define CRYPTONOTE_BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT    10000
#define CRYPTONOTE_BLOCKS_SYNCHRONIZING_DEFAULT_COUNT        200

#define CRYPTONOTE_GENESIS_TX                                "010a01ff0001eee2e48611029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101d4345cc30c53f75bd0a77f4ce70aee95f4d1fd051cac701f3e930ee789eea942"
#define CRYPTONOTE_GENESIS_TIMESTAMP                         1521379402
#define CRYPTONOTE_GENESIS_NONCE                             10000
#define CRYPTONOTE_GENESIS_REWARD                            ((uint64_t)0)

#define CRYPTONOTE_P2P_DEFAULT_PORT                          1111
#define CRYPTONOTE_RPC_DEFAULT_PORT                          1112

#define CRYPTONOTE_RPC_COMMAND_GET_BLOCKS_FAST_MAX_COUNT     1000
#define CRYPTONOTE_RPC_WALLET_CONNECTION_TIMEOUT             200000

#define CRYPTONOTE_P2P_LOCAL_WHITE_PEERLIST_LIMIT            1000
#define CRYPTONOTE_P2P_LOCAL_GRAY_PEERLIST_LIMIT             5000

#define CRYPTONOTE_MEMPOOL_DEFAULT_LIVETIME                  60*60*24
#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                       CRYPTONOTE_MEMPOOL_DEFAULT_LIVETIME / 2
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME        CRYPTONOTE_MEMPOOL_DEFAULT_LIVETIME

#define CRYPTONOTE_P2P_DEFAULT_CONNECTIONS_COUNT             8
#define CRYPTONOTE_P2P_DEFAULT_HANDSHAKE_INTERVAL            60
#define CRYPTONOTE_P2P_DEFAULT_PACKET_MAX_SIZE               50000000
#define CRYPTONOTE_P2P_DEFAULT_CONFIG_ID                     0
#define CRYPTONOTE_P2P_DEFAULT_PEERS_IN_HANDSHAKE            250
#define CRYPTONOTE_P2P_DEFAULT_CONNECTION_TIMEOUT            5000
#define CRYPTONOTE_P2P_DEFAULT_PING_CONNECTION_TIMEOUT       2000
#define CRYPTONOTE_P2P_DEFAULT_INVOKE_TIMEOUT                60*2*1000
#define CRYPTONOTE_P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT      5000
#define CRYPTONOTE_P2P_STAT_TRUSTED_PUB_KEY                  "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115"
#define CRYPTONOTE_P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT 70

#define CRYPTONOTE_BLOCKCHAINDATA_SAVE_DELAY                 60*60*1
#define CRYPTONOTE_CONNECTIONS_MAKER_DELAY                   1
#define CRYPTONOTE_PEERLIST_SAVE_DELAY                       60*30*1
#define CRYPTONOTE_REMOVE_STUCK_TX_DELAY                     30

#define CRYPTONOTE_NAME                                      "testnet"
#define CRYPTONOTE_POOLDATA_FILENAME                         "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME                   "blockchain.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_TEMP_FILENAME              "blockchain.bin.tmp"
#define CRYPTONOTE_P2P_NET_DATA_FILENAME                     "p2pstate.bin"
#define CRYPTONOTE_MINER_CONFIG_FILE_NAME                    "miner_conf.json"

#define THREAD_STACK_SIZE                                    5*1024*1024

#define ALLOW_DEBUG_COMMANDS
