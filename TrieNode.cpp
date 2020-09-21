#include "TrieNode.h"
#include "Trie.h"
#include <iostream>
#include <cstring>


TrieNode::TrieNode(char let,char* wo,TrieNode *FirstChild,TrieNode *NextSibling)
        {
            letter = let;
            strcpy(word2,wo);
            child = FirstChild;
            sibling = NextSibling;
        };