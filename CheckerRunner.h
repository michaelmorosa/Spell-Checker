// Author: Sean Davis

#ifndef CHECKRUNNER_H
#define	CHECKRUNNER_H

const int NUM_WORDS = 150497;
const int MAX_LENGTH = 33;

typedef struct
{
  char* word;
  int count;
  char** matches;
} MatchingWords;

typedef struct
{
  char word[MAX_LENGTH + 1];
}  DictionaryWord;




#endif	/* CHECKRUNNER_H */

