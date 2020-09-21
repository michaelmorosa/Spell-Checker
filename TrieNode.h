#ifndef CHECKER_TRIENODE_H
#define CHECKER_TRIENODE_H
#include "CheckerRunner.h"
#include <iostream>
#include <cstring>

class TrieNode {
    public:
        TrieNode *child=NULL;
        TrieNode *sibling=NULL;
        char letter = '\0';
        char word2[MAX_LENGTH+1];
        TrieNode(char let,char* wo,TrieNode *FirstChild,TrieNode *NextSibling);
        friend class Trie;
};


#endif //CHECKER_TRIENODE_H
