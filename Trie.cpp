#include "Trie.h"
#include "TrieNode.h"
#include <cstring>
#include <iostream>

Trie::Trie(const DictionaryWord *words,int count) {
    char tempword[50];
    strcpy(tempword,words[0].word);
    root = new TrieNode(words[0].word[0],tempword,NULL,NULL);
    for(int i = 1;i < count;i++){
        strcpy(word3, words[i].word);
        insert(root,0);
    }
}

void Trie::insert(TrieNode *node,int pos){
    if(word3[pos] == node->letter){
        if(!node->child){
            pos++;
            node->child = new TrieNode(word3[pos],word3,NULL,NULL);
        }
        else{
            pos++;
            insert(node->child,pos);
        }
    }
    else{
        if (!node->sibling){
            node->sibling = new TrieNode(word3[pos],word3,NULL,NULL);
        }
        else{
            insert(node->sibling,pos);
        }
    }
}

void Trie::findMatch(TrieNode *currentNode,const char *lookingFor, int pos, int ErrorCount){
    int ErrorCount2 = ErrorCount;
    if(strlen(lookingFor) == strlen(currentNode->word2)){
    for(int i = pos; lookingFor[i] && ErrorCount2 < 2; i++){
        if(lookingFor[i] != currentNode->word2[i]){
            ErrorCount2++;
        }
    }
    if(ErrorCount2 < 2){
        strcpy(matchingWords2[count2], currentNode->word2);
        count2++;
    }
    }
    if(lookingFor[pos] == currentNode->word2[pos]){
        if(currentNode->child){
            findMatch(currentNode->child,lookingFor,pos+1,ErrorCount);
        }
    }
    else{
        if(ErrorCount==0) {
            if(currentNode->child) {
                findMatch(currentNode->child, lookingFor, pos+1, ErrorCount + 1);
            }
        }
    }
    if(currentNode->sibling){
        findMatch(currentNode->sibling,lookingFor,pos,ErrorCount);
    }
}

bool Trie::findExact(TrieNode *currentNode,const char *lookingFor,int pos){
    if (strcmp(currentNode->word2,lookingFor) == 0){
        return true;
    }
    else{
        if (currentNode->letter == lookingFor[pos]){
            if (currentNode->child){
                findExact(currentNode->child,lookingFor,pos+1);
            }
            else{
                return false;
            }
        }
        else{
            if (currentNode->sibling){
                findExact(currentNode->sibling,lookingFor,pos);
            }
            else{
                return false;
            }
        }
    }
}