// tests.cpp -- your own tests for HashMap and TreeMap.
//
// Name:
// SDSU ID:
//
// Build and run with sanitizers:   make test
//
// Write tests for every public function, including edge cases. A few
// examples are provided to show the style. You will be asked about your
// tests in your code defense (for example, "which test would catch a
// missing rotation?").

#include <iostream>
#include <string>

#include "HashMap.h"
#include "TreeMap.h"

// ---- Minimal test harness (no external libraries needed) ----
static int g_checks = 0;
static int g_failures = 0;

#define CHECK(expr)                                                     \
    do {                                                                \
        ++g_checks;                                                     \
        if (!(expr)) {                                                  \
            ++g_failures;                                               \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__         \
                      << "  " #expr "\n";                               \
        }                                                               \
    } while (0)

// ---- HashMap tests ----

static void testHashMapEmpty() {
    HashMap<int> m;
    CHECK(m.empty());
    CHECK(m.size() == 0);
    CHECK(!m.contains("anything"));
    CHECK(!m.get("anything").has_value());
}

static void testHashMapPutGet() {
    HashMap<int> m;
    CHECK(m.put("apple", 1));
    CHECK(m.get("apple") == 1);
    CHECK(!m.put("apple", 2));   // replace, not insert
    CHECK(m.get("apple") == 2);
    CHECK(m.size() == 1);
}

// TODO: more HashMap tests (remove, resizing, collisions, many keys, ...)

// ---- TreeMap tests ----

static void testTreeMapEmpty() {
    TreeMap<int, int> t;
    CHECK(t.empty());
    CHECK(t.height() == -1);
    CHECK(!t.floorKey(5).has_value());
    CHECK(t.keys().empty());
}

// TODO: more TreeMap tests (ordering, floorKey cases, height bound, ...)

int main() {
    testHashMapEmpty();
    testHashMapPutGet();
    testTreeMapEmpty();

    std::cout << (g_checks - g_failures) << " / " << g_checks
              << " checks passed\n";
    return g_failures == 0 ? 0 : 1;
}
