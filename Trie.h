#ifndef CHECKER_TRIE_H
#define CHECKER_TRIE_H
#include "TrieNode.h"

class Trie {
public:
    char word3[MAX_LENGTH+1];
    char let5;
    TrieNode *root;
    Trie(const DictionaryWord *words,int count);
    void insert(TrieNode *node,int pos);
    bool findExact(TrieNode *currentNode,const char *lookingFor, int pos);
    void findMatch(TrieNode *currentNode,const char *lookingFor, int pos, int ErrorCount);
    char matchingWords2[100][MAX_LENGTH + 1];
    int count2;
};


#endif //CHECKER_TRIE_H
