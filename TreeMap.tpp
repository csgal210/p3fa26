// TreeMap.tpp -- implementation of TreeMap<K, V>. Included at the end of TreeMap.h.
//
// Name:
// SDSU ID:
//
// Every function below is a stub that compiles but does nothing useful.
// Replace each TODO with your implementation. Most of these are easiest to
// write with recursive private helpers that you declare in TreeMap.h.

#include <stdexcept>

template <std::totally_ordered K, class V>
TreeMap<K, V>::~TreeMap() {
    // TODO
}

template <std::totally_ordered K, class V>
bool TreeMap<K, V>::put(const K& key, const V& value) {
    // TODO
    (void)key; (void)value;
    return false;
}

template <std::totally_ordered K, class V>
std::optional<V> TreeMap<K, V>::get(const K& key) const {
    // TODO
    (void)key;
    return std::nullopt;
}

template <std::totally_ordered K, class V>
bool TreeMap<K, V>::contains(const K& key) const {
    // TODO
    (void)key;
    return false;
}

template <std::totally_ordered K, class V>
std::size_t TreeMap<K, V>::size() const {
    return size_;
}

template <std::totally_ordered K, class V>
bool TreeMap<K, V>::empty() const {
    return size_ == 0;
}

template <std::totally_ordered K, class V>
int TreeMap<K, V>::height() const {
    // TODO
    return -1;
}

template <std::totally_ordered K, class V>
std::optional<K> TreeMap<K, V>::floorKey(const K& key) const {
    // TODO
    (void)key;
    return std::nullopt;
}

template <std::totally_ordered K, class V>
std::vector<K> TreeMap<K, V>::keys() const {
    // TODO
    return {};
}

template <std::totally_ordered K, class V>
bool TreeMap<K, V>::remove(const K& key) {
    // EXTRA CREDIT. Leave this stub unchanged if you do not attempt it.
    (void)key;
    throw std::logic_error("TreeMap::remove not implemented");
}
