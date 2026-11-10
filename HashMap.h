// HashMap.h -- CS3 Programming Assignment #3
//
// A map from std::string keys to values of type V, implemented as a hash
// table with separate chaining. Each bucket holds a singly linked chain of
// Nodes that YOU allocate and free. Do not use std::list, std::forward_list,
// std::unordered_map, std::map, or std::hash anywhere in this file or in
// HashMap.tpp.
//
// Name:
// SDSU ID:
//
// RULES
//  - Do NOT change anything in the public section. The grader compiles
//    against this exact public interface.
//  - You MAY add private data members and private helper functions.
//  - Do NOT rename or remove the private members provided below.
//  - Implement every function in HashMap.tpp.

#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstddef>
#include <optional>
#include <string>
#include <vector>

template <class V>
class HashMap {
public:
    // Default bucket count used by the default constructor.
    static constexpr std::size_t DEFAULT_BUCKETS = 16;

    // Postcondition: an empty map with DEFAULT_BUCKETS buckets.
    HashMap();

    // Precondition:  initialBuckets >= 1.
    // Postcondition: an empty map with exactly initialBuckets buckets.
    explicit HashMap(std::size_t initialBuckets);

    // Postcondition: every node has been freed.
    ~HashMap();

    // Copying and moving are disabled for this assignment.
    HashMap(const HashMap&) = delete;
    HashMap& operator=(const HashMap&) = delete;
    HashMap(HashMap&&) = delete;
    HashMap& operator=(HashMap&&) = delete;

    // Postcondition: key maps to value. If key was already present, its old
    // value is replaced and size() is unchanged. The table may resize;
    // after put returns, loadFactor() must be at most 2.0.
    // Returns: true if key was newly inserted, false if an existing value
    //          was replaced.
    bool put(const std::string& key, const V& value);

    // Returns: the value mapped to key, or std::nullopt if key is absent.
    std::optional<V> get(const std::string& key) const;

    // Returns: true if key is present.
    bool contains(const std::string& key) const;

    // Postcondition: key is absent and its node has been freed.
    // Returns: true if key was present (and removed), false otherwise.
    // remove() never shrinks the bucket array.
    bool remove(const std::string& key);

    // Returns: number of key-value pairs stored.
    std::size_t size() const;

    // Returns: size() == 0.
    bool empty() const;

    // ---- Instrumentation (used by the grader and by your experiments) ----

    // Returns: current number of buckets.
    std::size_t bucketCount() const;

    // Returns: size() / bucketCount() as a double.
    double loadFactor() const;

    // Returns: the number of nodes in the longest chain (0 if empty).
    std::size_t longestChain() const;

    // Hash function for keys. You design this. It must not call std::hash.
    // Returns: a hash value for s; the bucket index is
    //          hashString(s) % bucketCount().
    static std::size_t hashString(const std::string& s);

private:
    struct Node {
        std::string key;
        V value;
        Node* next;
    };

    std::vector<Node*> buckets_;
    std::size_t size_ = 0;

    // Suggested helper: move every node into a new bucket array of
    // newBucketCount buckets WITHOUT allocating new nodes.
    void rehash(std::size_t newBucketCount);

    // Add your own private members below this line.
};

#include "HashMap.tpp"

#endif // HASHMAP_H
