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

#include <cstddef>
#include <fstream>
#include <iomanip>
#include <ios>
#include <string>

#include "warnings.h"
#include "crypto/hash.h"
#include "../io.h"

using namespace std;
using namespace crypto;
typedef crypto::hash chash;

PUSH_WARNINGS
DISABLE_VS_WARNINGS(4297)
extern "C" {
  static void hash_tree(const void *data, size_t length, char *hash) {
    if ((length & 31) != 0) {
      throw ios_base::failure("Invalid input length for tree_hash");
    }
    tree_hash((const char (*)[crypto::HASH_SIZE]) data, length >> 5, hash);
  }
}
POP_WARNINGS

extern "C" typedef void hash_f(const void *, size_t, char *);
struct hash_func {
  const string name;
  hash_f &f;
} hashes[] = {{"fast", cn_fast_hash}, {"slow-2048kb", cn_slow_hash_2048kb},
  {"slow-512kb", cn_slow_hash_512kb}, {"tree", hash_tree},
  {"extra-blake", hash_extra_blake}, {"extra-groestl", hash_extra_groestl},
  {"extra-jh", hash_extra_jh}, {"extra-skein", hash_extra_skein}};

int main(int argc, char *argv[]) {
  hash_f *f;
  hash_func *hf;
  fstream input;
  vector<char> data;
  chash expected, actual;
  size_t test = 0;
  bool error = false;
  if (argc != 3) {
    cerr << "Wrong number of arguments" << endl;
    return 1;
  }
  for (hf = hashes;; hf++) {
    if (hf >= &hashes[sizeof(hashes) / sizeof(hash_func)]) {
      cerr << "Unknown function" << endl;
      return 1;
    }
    if (argv[1] == hf->name) {
      f = &hf->f;
      break;
    }
  }
  input.open(argv[2], ios_base::in);
  for (;;) {
    ++test;
    input.exceptions(ios_base::badbit);
    get(input, expected);
    if (input.rdstate() & ios_base::eofbit) {
      break;
    }
    input.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    input.clear(input.rdstate());
    get(input, data);
    f(data.data(), data.size(), (char *) &actual);
    if (expected != actual) {
      size_t i;
      cerr << "Hash mismatch on test " << test << endl << "Input: ";
      if (data.size() == 0) {
        cerr << "empty";
      } else {
        for (i = 0; i < data.size(); i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(static_cast<unsigned char>(data[i]));
        }
      }
      cerr << endl << "Expected hash: ";
      for (i = 0; i < 32; i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(reinterpret_cast<unsigned char *>(&expected)[i]);
      }
      cerr << endl << "Actual hash: ";
      for (i = 0; i < 32; i++) {
          cerr << setbase(16) << setw(2) << setfill('0') << int(reinterpret_cast<unsigned char *>(&actual)[i]);
      }
      cerr << endl;
      error = true;
    }
  }
  return error ? 1 : 0;
}
