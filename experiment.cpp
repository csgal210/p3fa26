// experiment.cpp -- measurements for Part C.
//
// Name:
// SDSU ID:
//
// Build:  make experiment
// Run:    ./experiment <your SDSU ID>
//
// The program writes four CSV files in the current directory. The headers
// are fixed so the instructor or ISA can re-run your program and compare
// results; do not change them. Fill in each TODO block.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

#include "HashMap.h"
#include "TreeMap.h"

// ---- Provided helpers: do not modify ----

// These helpers use only the raw output of std::mt19937_64, which the C++
// standard fixes exactly, so results are identical on every compiler and OS.
// (std::uniform_int_distribution and std::shuffle are NOT portable this way.)

// n distinct random lowercase keys of length 8-12, reproducible from seed.
static std::vector<std::string> makeKeys(std::uint64_t seed, std::size_t n) {
    std::mt19937_64 rng(seed);
    std::unordered_set<std::string> seen;
    std::vector<std::string> keys;
    keys.reserve(n);
    while (keys.size() < n) {
        std::string s(static_cast<std::size_t>(8 + rng() % 5), 'a');
        for (char& c : s) c = static_cast<char>('a' + rng() % 26);
        if (seen.insert(s).second) keys.push_back(s);
    }
    return keys;
}

// The integers 0..n-1 in a random order, reproducible from seed (Fisher-Yates).
[[maybe_unused]] static std::vector<int> shuffledInts(std::uint64_t seed, int n) {
    std::vector<int> v(static_cast<std::size_t>(n));
    std::iota(v.begin(), v.end(), 0);
    std::mt19937_64 rng(seed);
    for (std::size_t i = v.size(); i > 1; --i)
        std::swap(v[i - 1], v[rng() % i]);
    return v;
}

// A deliberately weak hash: the sum of the character codes.
[[maybe_unused]] static std::size_t weakHash(const std::string& s) {
    std::size_t h = 0;
    for (unsigned char c : s) h += c;
    return h;
}

// Seconds elapsed while running f().
template <class F>
static double timeIt(F f) {
    auto start = std::chrono::steady_clock::now();
    f();
    auto stop = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(stop - start).count();
}

// ---- Experiments ----

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <SDSU ID>\n";
        return 1;
    }
    const std::uint64_t seed = std::strtoull(argv[1], nullptr, 10);
    const std::size_t N = 200000;
    const std::vector<std::string> keys = makeKeys(seed, N);

    // E1: HashMap growth. Insert all N keys into one HashMap<int>, starting
    // from the default constructor. After every 1000th insert, write one row.
    {
        std::ofstream out("hash_growth.csv");
        out << "n,bucket_count,load_factor,longest_chain\n";
        // TODO
    }

    // E2: Hash quality. For both weakHash and HashMap<int>::hashString,
    // place all N keys into 65536 buckets (index = hash % 65536) WITHOUT
    // using the HashMap class, then count how many buckets have each chain
    // length. Write one row per (hash, chain_length) pair that occurs.
    {
        std::ofstream out("hash_quality.csv");
        out << "hash,chain_length,bucket_count\n";   // hash is "weak" or "mine"
        // TODO
    }

    // E3: Tree height. For n = 2^10, 2^11, ..., 2^17, build a TreeMap<int,int>
    // from keys 0..n-1 inserted (a) in ascending order and (b) in the order
    // given by shuffledInts(seed, n).
    {
        std::ofstream out("tree_height.csv");
        out << "n,order,height,log2_n,bound_2log2_n_plus_1\n";  // order is "sorted" or "random"
        // TODO
    }

    // E4: Timing. Using the N string keys, time (a) putting every key and
    // (b) getting every key, for HashMap<int> and TreeMap<std::string,int>.
    // Repeat each measurement 3 times and report the median.
    {
        std::ofstream out("timing.csv");
        out << "structure,operation,n,median_seconds\n";  // structure is "hash" or "tree"; operation is "put" or "get"
        // TODO
    }

    std::cout << "Wrote hash_growth.csv, hash_quality.csv, tree_height.csv, timing.csv\n";
    return 0;
}
