# Makefile -- CS3 Programming Assignment #3
#
#   make test         build tests.cpp with sanitizers and run it
#   make experiment   build experiment.cpp optimized (run: ./experiment <SDSU ID>)
#   make clean
#
# Requires g++ 10+ or clang++ 12+ (C++20). On macOS, clang's
# AddressSanitizer does not report leaks; use Linux or WSL to check leaks.

CXX      ?= g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic
SANITIZE := -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer
HEADERS  := HashMap.h HashMap.tpp TreeMap.h TreeMap.tpp

.PHONY: test experiment clean

tests: tests.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SANITIZE) tests.cpp -o tests

test: tests
	./tests

experiment: experiment.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -O2 experiment.cpp -o experiment

clean:
	rm -f tests experiment *.csv
