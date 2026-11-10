// HashMap.tpp -- implementation of HashMap<V>. Included at the end of HashMap.h.
//
// Name:
// SDSU ID:
//
// Every function below is a stub that compiles but does nothing useful.
// Replace each TODO with your implementation.

template <class V>
HashMap<V>::HashMap() : HashMap(DEFAULT_BUCKETS) {}

template <class V>
HashMap<V>::HashMap(std::size_t initialBuckets) {
    // TODO
    (void)initialBuckets;
}

template <class V>
HashMap<V>::~HashMap() {
    // TODO
}

template <class V>
bool HashMap<V>::put(const std::string& key, const V& value) {
    // TODO
    (void)key; (void)value;
    return false;
}

template <class V>
std::optional<V> HashMap<V>::get(const std::string& key) const {
    // TODO
    (void)key;
    return std::nullopt;
}

template <class V>
bool HashMap<V>::contains(const std::string& key) const {
    // TODO
    (void)key;
    return false;
}

template <class V>
bool HashMap<V>::remove(const std::string& key) {
    // TODO
    (void)key;
    return false;
}

template <class V>
std::size_t HashMap<V>::size() const {
    return size_;
}

template <class V>
bool HashMap<V>::empty() const {
    return size_ == 0;
}

template <class V>
std::size_t HashMap<V>::bucketCount() const {
    return buckets_.size();
}

template <class V>
double HashMap<V>::loadFactor() const {
    // TODO
    return 0.0;
}

template <class V>
std::size_t HashMap<V>::longestChain() const {
    // TODO
    return 0;
}

template <class V>
std::size_t HashMap<V>::hashString(const std::string& s) {
    // TODO: design your own hash function. Do not call std::hash.
    // Justify your choice in your report.
    (void)s;
    return 0;
}

template <class V>
void HashMap<V>::rehash(std::size_t newBucketCount) {
    // TODO
    (void)newBucketCount;
}
