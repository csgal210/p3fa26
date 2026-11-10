// TreeMap.h -- CS3 Programming Assignment #3
//
// An ordered map from keys of type K to values of type V, implemented as a
// red-black binary search tree. You may implement EITHER:
//   (a) a standard red-black tree (as in the textbook, equivalent to a
//       2-4 tree), or
//   (b) a left-leaning red-black tree (LLRB, equivalent to a 2-3 tree;
//       see the assignment handout for its definition).
// State which one you implemented in the comment below.
//
// Name:
// SDSU ID:
// Variant implemented (standard RB or LLRB):
//
// RULES
//  - Do NOT change anything in the public section. The grader compiles
//    against this exact public interface.
//  - Do NOT rename or remove the private members provided below; some
//    grading tests inspect them. You MAY add private data members and
//    private helper functions
//    (for example, a parent pointer in Node if you use the standard variant).
//  - Do not use std::map, std::set, or any other library tree.
//  - Implement every function in TreeMap.tpp.

#ifndef TREEMAP_H
#define TREEMAP_H

#include <concepts>
#include <cstddef>
#include <optional>
#include <vector>

template <std::totally_ordered K, class V>
class TreeMap {
public:
    // Postcondition: an empty map.
    TreeMap() = default;

    // Postcondition: every node has been freed.
    ~TreeMap();

    // Copying and moving are disabled for this assignment.
    TreeMap(const TreeMap&) = delete;
    TreeMap& operator=(const TreeMap&) = delete;
    TreeMap(TreeMap&&) = delete;
    TreeMap& operator=(TreeMap&&) = delete;

    // Postcondition: key maps to value and every red-black property holds.
    // If key was already present, its old value is replaced, size() is
    // unchanged, and the tree's shape is unchanged.
    // Returns: true if key was newly inserted, false if a value was replaced.
    bool put(const K& key, const V& value);

    // Returns: the value mapped to key, or std::nullopt if key is absent.
    std::optional<V> get(const K& key) const;

    // Returns: true if key is present.
    bool contains(const K& key) const;

    // Returns: number of key-value pairs stored.
    std::size_t size() const;

    // Returns: size() == 0.
    bool empty() const;

    // Returns: the number of EDGES on the longest path from the root down to
    //          a node with no children. An empty tree has height -1; a tree
    //          with one node has height 0.
    int height() const;

    // Returns: the largest key that is <= key, or std::nullopt if every key
    //          in the map is greater than key (or the map is empty).
    std::optional<K> floorKey(const K& key) const;

    // Returns: all keys in ascending order.
    std::vector<K> keys() const;

    // EXTRA CREDIT. Leave the provided stub in place if you skip it.
    // Postcondition: key is absent, its node has been freed, and every
    // red-black property holds.
    // Returns: true if key was present (and removed), false otherwise.
    bool remove(const K& key);

private:
    enum class Color { Red, Black };

    struct Node {
        K key;
        V value;
        Color color;
        Node* left;
        Node* right;
    };

    Node* root_ = nullptr;
    std::size_t size_ = 0;

    // Add your own private members below this line.
};

#include "TreeMap.tpp"

#endif // TREEMAP_H
