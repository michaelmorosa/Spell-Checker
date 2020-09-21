#ifndef CHECKER_H
#define	CHECKER_H

#include "CheckerRunner.h"

class TrieNode {
public:
    TrieNode *child=NULL;
    TrieNode *sibling=NULL;
    char letter = '\0';
    char word2[MAX_LENGTH+1];
    TrieNode(char let,char* wo,TrieNode *FirstChild,TrieNode *NextSibling);
    friend class Trie;
};

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

class Checker {
public:
    Checker(const DictionaryWord *words, int numWords);
    void findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1],int *count);
    Trie tree;
}; // class Checker

#endif	// CHECKER_H


