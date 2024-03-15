/*
 * Student ID: 201535181
 * Student Name: Robert Onuma
 * Email: sgronuma@liverpool.ac.uk
 *
 * User: sgronuma
 *
 * Problem ID: 1090
 * RunID: 55546
 * Result: Wrong Answer
 * Note that OJ system adds new lines, while in other computer systems, it doesn't
 *add new lines unnecessarilly.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char inputLine[100];
  char **individWrdsPtr;
  int *individWrdsCount;
  char *token;
  char **allWordsPtr;
  int idx1 = 0;
  int idx2;
  int individWrdsIdx = 0;
  int inArrFlag = 0;

  allWordsPtr = (char**)malloc(300 * sizeof(char*));
  if (allWordsPtr == NULL) {
    exit(1);
  }

  /*the loop below extracts every word from the text*/
  while (1) {
    fgets(&inputLine, 100, stdin);

    token = strtok(inputLine, " ,.");
    while (token != NULL) {
      char *wordPtr = (char*)malloc(31 * sizeof(char));
      if (wordPtr == NULL) {
        exit(1);
      }
      *token = tolower(*token);
      idx2 = 0;
      for (int i = 0; i < strlen(token); i++) {
        if (isalpha(token[i])) {
          *(wordPtr+idx2) = token[i];
          idx2++;
        }
      }
      *(allWordsPtr+idx1) = wordPtr;
      idx1++;
      token = strtok(NULL, " ,.");
    }
    if (feof(stdin)) {
      break;
    }
  }

  individWrdsPtr = (char**)malloc(300 * sizeof(char*));
  if (individWrdsPtr == NULL) {
    exit(1);
  }
  individWrdsCount = (int*)malloc(300 * sizeof(int));
  if (individWrdsCount == NULL) {
    exit(1);
  }

  /*the loop below extracts the individual words and their count*/
  for (int i = 0; i < idx1; i++) {
    int ret;
    for (int j = 0; j < individWrdsIdx; j++) {
      ret = strcmp(allWordsPtr[i], individWrdsPtr[j]);
      if (ret == 0) {
        inArrFlag = 1;
      }
    }

    if (inArrFlag == 0) {
      int counter = 0;
      individWrdsPtr[individWrdsIdx]  = allWordsPtr[i];
      for (int j = 0; j < idx1; j++) {
        ret = strcmp(allWordsPtr[i], allWordsPtr[j]);
        if (ret == 0) {
          counter++;
        }
      }

      individWrdsCount[individWrdsIdx] = counter;

      if(individWrdsIdx > 0) {
        /*the loop below is my sorting algorithm*/
        for (int a = individWrdsIdx; a > 0; a--) {
          char* word1 = individWrdsPtr[a-1];
          char* word2 = individWrdsPtr[a];
          int b = 0;
          int exitFlag = 0;
          while ((word1[b] != '\0' && word2[b] != '\0') && word1[b] == word2[b]) {
            b++;
          }
          if (word1[b] - word2[b] > 0) {
            char* temp1 = individWrdsPtr[a-1];
            individWrdsPtr[a-1] = individWrdsPtr[a];
            individWrdsPtr[a] = temp1;

            int temp2 = individWrdsCount[a-1];
            individWrdsCount[a-1] = individWrdsCount[a];
            individWrdsCount[a] = temp2;
          }
        }
      }
      individWrdsIdx++;
    }
    inArrFlag = 0;
  }

  /*printing of the indiviual words and their respective count takes place below*/
  for (int a = 0; a < individWrdsIdx; a++) {
    if (isalpha(individWrdsPtr[a][0])) {
      printf("%s => %d \n", individWrdsPtr[a], individWrdsCount[a]);
    }
  }
  free(allWordsPtr);
  free(individWrdsPtr);
  free(individWrdsCount);


  return 0;
}
