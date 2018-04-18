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

#include <cstring>
#include <iostream>

#include <boost/config.hpp>

#ifdef BOOST_WINDOWS
#include <windows.h>
#endif

void set_process_affinity(int core)
{
#if defined (__APPLE__)
    return;
#elif defined(BOOST_WINDOWS)
  DWORD_PTR mask = 1;
  for (int i = 0; i < core; ++i)
  {
    mask <<= 1;
  }
  ::SetProcessAffinityMask(::GetCurrentProcess(), core);
#elif defined(BOOST_HAS_PTHREADS)
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(core, &cpuset);
  if (0 != ::pthread_setaffinity_np(::pthread_self(), sizeof(cpuset), &cpuset))
  {
    std::cout << "pthread_setaffinity_np - ERROR" << std::endl;
  }
#endif
}

void set_thread_high_priority()
{
#if defined(__APPLE__)
    return;
#elif defined(BOOST_WINDOWS)
  ::SetPriorityClass(::GetCurrentProcess(), HIGH_PRIORITY_CLASS);
#elif defined(BOOST_HAS_PTHREADS)
  pthread_attr_t attr;
  int policy = 0;
  int max_prio_for_policy = 0;

  ::pthread_attr_init(&attr);
  ::pthread_attr_getschedpolicy(&attr, &policy);
  max_prio_for_policy = ::sched_get_priority_max(policy);

  if (0 != ::pthread_setschedprio(::pthread_self(), max_prio_for_policy))
  {
    std::cout << "pthread_setschedprio - ERROR" << std::endl;
  }

  ::pthread_attr_destroy(&attr);
#endif
}
