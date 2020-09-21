#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "CheckerRunner.h"
#include "checker.h"
#include "CPUTimer.h"
using namespace std;


MatchingWords* readTesterFile(const char *filename, int *numWords)
{
  char line[1000], *ptr;
  ifstream inf(filename);
  inf >> *numWords;
  MatchingWords *matchingWords = new MatchingWords[*numWords];
  inf.ignore(1000, '\n');
  
  for(int i = 0; i < *numWords; i++)
  {
    inf.getline(line, 1000);
    ptr = strtok(line, ",");
    matchingWords[i].word = new char[strlen(ptr) + 1];
    strcpy(matchingWords[i].word, ptr);
    matchingWords[i].count = atoi(strtok(NULL, ","));
    matchingWords[i].matches = new char*[matchingWords[i].count];
    
    for(int j = 0; j < matchingWords[i].count; j++)
    {
      ptr = strtok(NULL, ",");
      matchingWords[i].matches[j] = new char[strlen(ptr) + 1];
      strcpy(matchingWords[i].matches[j], ptr);
    } // for each matching word
  }  // for each word
  
  return matchingWords;
}  // readTesterFile()


DictionaryWord* readWordsFile()
{
  int count = 0;
  char line[100];
  DictionaryWord *words = new DictionaryWord[NUM_WORDS];
  ifstream inf("words.txt");
  
  while(inf.getline(line, 100))
    strcpy(words[count++].word, line);

  return words;
}  // readWordsFile()

int main(int argc, char **argv)
{
  char word[MAX_LENGTH + 1], matchingWords[100][MAX_LENGTH + 1];
  int numWords, count;
  DictionaryWord *words = readWordsFile();
  MatchingWords *matchingWordsKey = readTesterFile(argv[1], &numWords);
  CPUTimer ct;
  Checker *checker = new Checker((const DictionaryWord*) words, NUM_WORDS);
  delete words;
  for(int i = 0; i < numWords; i++)
  {
    strcpy(word, matchingWordsKey[i].word);
    checker->findWord(word, matchingWords, &count);
      
    if(count != matchingWordsKey[i].count)
    {
      cout << "Incorrect count for trial# " << i << " for " 
        << matchingWordsKey[i].word << " should be " 
        << matchingWordsKey[i].count << " but received " << count << endl;
    }
    else // correct count
    {
      for(int j = 0; j < count; j++)
      {
        bool OK = false;
        for(int k = 0; !OK && k < count; k++)
          if(strcmp(matchingWordsKey[i].matches[j], matchingWords[k]) == 0)
            OK = true;
        
        if(!OK)
        {
          cout << "Words don't match for trial# " << i << " for "
             << matchingWordsKey[i].word << " they do not include "
             << matchingWordsKey[i].matches[j] << endl;
        } // if invalid match
      } // for j
    } // else correct count
  }  // for each word
  
  cout << "CPU Time: " << ct.cur_CPUTime() << endl;
  return 0;
}
