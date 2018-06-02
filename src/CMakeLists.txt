# Copyright (c) 2018, The CryoNote Developers.
# Portions Copyright (c) 2012-2013, The CryptoNote Developers.
#
# All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

add_definitions(-DSTATICLIB)

file(GLOB_RECURSE COMMON common/*)
file(GLOB_RECURSE CRYPTO crypto/*)
file(GLOB_RECURSE CRYPTONOTE_CORE cryptonote_core/*)
file(GLOB_RECURSE CRYPTONOTE_PROTOCOL cryptonote_protocol/*)
file(GLOB_RECURSE DAEMON daemon/*)
file(GLOB_RECURSE P2P p2p/*)
file(GLOB_RECURSE RPC rpc/*)
file(GLOB_RECURSE SIMPLEWALLET simplewallet/*)
file(GLOB_RECURSE CONN_TOOL connectivity_tool/*)
file(GLOB_RECURSE WALLET wallet/*)
file(GLOB_RECURSE MINER miner/*)

source_group(common FILES ${COMMON})
source_group(crypto FILES ${CRYPTO})
source_group(cryptonote_core FILES ${CRYPTONOTE_CORE})
source_group(cryptonote_protocol FILES ${CRYPTONOTE_PROTOCOL})
source_group(daemon FILES ${DAEMON})
source_group(p2p FILES ${P2P})
source_group(rpc FILES ${RPC})
source_group(simplewallet FILES ${SIMPLEWALLET})
source_group(connectivity-tool FILES ${CONN_TOOL})
source_group(wallet FILES ${WALLET})

add_library(common ${COMMON})
add_library(crypto ${CRYPTO})
add_library(cryptonote_core ${CRYPTONOTE_CORE})
add_library(rpc ${RPC})
add_library(wallet ${WALLET})

add_executable(daemon ${DAEMON} ${P2P} ${CRYPTONOTE_PROTOCOL})
add_executable(connectivity_tool ${CONN_TOOL})
add_executable(simplewallet ${SIMPLEWALLET})

target_link_libraries(daemon rpc cryptonote_core crypto common libminiupnpc-static ${Boost_LIBRARIES})
target_link_libraries(connectivity_tool cryptonote_core crypto common ${Boost_LIBRARIES})
target_link_libraries(simplewallet wallet rpc cryptonote_core crypto common libminiupnpc-static ${Boost_LIBRARIES})

add_dependencies(daemon version)
add_dependencies(rpc version)
add_dependencies(simplewallet version)

set_property(TARGET common crypto cryptonote_core rpc wallet PROPERTY FOLDER "libs")
set_property(TARGET daemon simplewallet connectivity_tool PROPERTY FOLDER "prog")
set_property(TARGET daemon PROPERTY OUTPUT_NAME "cryonoted")
