cmake_minimum_required(VERSION 3.14)
project(Checker)

set(CMAKE_CXX_STANDARD 14)

add_executable(Checker CheckerRunner.cpp CheckerRunner.h checker.h checker.cpp TrieNode.h TrieNode.cpp Trie.h Trie.cpp)