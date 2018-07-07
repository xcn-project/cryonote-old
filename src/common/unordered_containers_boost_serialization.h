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

#include <boost/serialization/split_free.hpp>
#include <unordered_map>
#include <unordered_set>

namespace boost
{
  namespace serialization
  {
    template <class Archive, class h_key, class hval>
    inline void save(Archive &a, const std::unordered_map<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      size_t s = x.size();
      a << s;
      for (auto& v : x)
      {
        a << v.first;
        a << v.second;
      }
    }

    template <class Archive, class h_key, class hval>
    inline void load(Archive &a, std::unordered_map<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      x.clear();
      size_t s = 0;
      a >> s;
      for(size_t i = 0; i != s; i++)
      {
        h_key k;
        hval v;
        a >> k;
        a >> v;
        x.insert(std::pair<h_key, hval>(k, v));
      }
    }


    template <class Archive, class h_key, class hval>
    inline void save(Archive &a, const std::unordered_multimap<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      size_t s = x.size();
      a << s;
      for (auto& v : x)
      {
        a << v.first;
        a << v.second;
      }
    }

    template <class Archive, class h_key, class hval>
    inline void load(Archive &a, std::unordered_multimap<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      x.clear();
      size_t s = 0;
      a >> s;
      for(size_t i = 0; i != s; i++)
      {
        h_key k;
        hval v;
        a >> k;
        a >> v;
        x.emplace(k, v);
      }
    }


    template <class Archive, class hval>
    inline void save(Archive &a, const std::unordered_set<hval> &x, const boost::serialization::version_type ver)
    {
      size_t s = x.size();
      a << s;
      for (auto& v : x)
      {
        a << v;
      }
    }

    template <class Archive, class hval>
    inline void load(Archive &a, std::unordered_set<hval> &x, const boost::serialization::version_type ver)
    {
      x.clear();
      size_t s = 0;
      a >> s;
      for(size_t i = 0; i != s; i++)
      {
        hval v;
        a >> v;
        x.insert(v);
      }
    }


    template <class Archive, class h_key, class hval>
    inline void serialize(Archive &a, std::unordered_map<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      split_free(a, x, ver);
    }

    template <class Archive, class h_key, class hval>
    inline void serialize(Archive &a, std::unordered_multimap<h_key, hval> &x, const boost::serialization::version_type ver)
    {
      split_free(a, x, ver);
    }

    template <class Archive, class hval>
    inline void serialize(Archive &a, std::unordered_set<hval> &x, const boost::serialization::version_type ver)
    {
      split_free(a, x, ver);
    }
  }
}
