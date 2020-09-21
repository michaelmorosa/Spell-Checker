//CheckerRunner.cpp CheckerRunner.h checker.h checker.cpp TrieNode.h TrieNode.cpp Trie.h Trie.cpp
#include <iostream>
#include <cstring>

class TrieNode{
public:
    TrieNode *child=NULL;
    TrieNode *sibling=NULL;
    char letter = '\0';
    char word2[50];
    char word3[50];
};

void insert(TrieNode *node,int pos){
    if(node->word2[pos] == node->letter){
        if(!node->child){
            pos++;
            node->child = new TrieNode(node->word3[pos],word3,NULL,NULL);
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

bool findExact(TrieNode *currentNode,const char *lookingFor,int pos){
    if (currentNode->word2 == lookingFor){
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

int main(int argc, char **argv) {
    std::ifstream file(argv[1]);
    char string[50];
    char tempword[50];
    char word3[50];
    strcpy(tempword,words[0].word);
    root = new TrieNode(words[0].word[0],tempword,NULL,NULL);
    for(int i = 1;i < count;i++){
        strcpy(word3, words[i].word);
        insert(root,0);
    }
    TrieNode* root = new TrieNode;
    while (file.getline(string, 50)){
        insert(root, word);}
    if (find(root, "coalitioner")){
        std::cout << "FIRST TRY BABY";
    }
    findWithError(root, "brutalizy", 0, false);
    //std::cout << answers[0];


    return 0;
}