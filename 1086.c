/*
 * Student ID: 201535181
 * Student Name: Robert Onuma
 * Email: sgronuma@liverpool.ac.uk
 *
 * User: sgronuma
 *
 * Problem ID: 1086
 * RunID: 55544
 * Result: Wrong Answer
 * Note that OJ system adds new lines, while in other computer systems, it doesn't
 *add new lines unnecessarilly.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char eOrC, artFileChar, reoccuringChar;
  int multiplyValue, intValue;
  multiplyValue = 0;
  reoccuringChar = '\0';
  int charCount = 1;
  scanf("%c", &eOrC);

  if (eOrC == 'C') {
    /*the loop below counts each character and encrypts it if the count is
    greater than one*/
    while (scanf("%c", &artFileChar) != EOF) {
      if (artFileChar != '\n') {

        if (reoccuringChar == artFileChar) {
          charCount++;

        }
        else {
          if (charCount > 1) {
            printf("%c%c%d*", reoccuringChar, reoccuringChar, charCount);
          }
          else {
            if (reoccuringChar != '\0' && reoccuringChar != '\n') {
              printf("%c", reoccuringChar);
            }
          }
          charCount = 1;
        }
        reoccuringChar = artFileChar;
      }
      else {
        if (charCount > 1) {
          printf("%c%c%d*", reoccuringChar, reoccuringChar, charCount);
        }
        else {
          if (reoccuringChar != '\0' && reoccuringChar != '\n') {
            printf("%c", reoccuringChar);
          }
        }
        reoccuringChar = '\0';
        charCount = 1;
        printf("\n");
      }
    }
    if (artFileChar != '\n') {
      if (charCount > 1) {
        printf("%c%c%d*", reoccuringChar, reoccuringChar, charCount);
      }
      else {
        if (reoccuringChar != '\0' && reoccuringChar != '\n') {
          printf("%c", reoccuringChar);
        }
      }
    }

  }

  if (eOrC == 'E') {
    /*the loop below reads in each character and expands it based on the count*/
    while (scanf("%c", &artFileChar) != EOF) {
      if (artFileChar != '\n') {
        if (charCount > 1) {
          if (!isdigit(artFileChar)) {
            for (int i = 0; i < multiplyValue-1; i++) {
              printf("%c", reoccuringChar);
            }
            charCount = 1;
            multiplyValue = 0;
          }
          else {
            intValue = ((int) artFileChar) - 48;
            multiplyValue *= 10;
            multiplyValue += intValue;
          }
        }
        else {
          if (reoccuringChar == artFileChar) {
            charCount++;
          }

          if (charCount == 1) {
            if (reoccuringChar != '\0' && artFileChar != '\n') {
              printf("%c", artFileChar);
            }
            reoccuringChar = artFileChar;
          }
        }
      }
      else {
        if (charCount > 1) {
          if (!isdigit(artFileChar)) {
            for (int i = 0; i < multiplyValue-1; i++) {
              printf("%c", reoccuringChar);
            }
            charCount = 1;
            multiplyValue = 0;
          }
          else {
            intValue = ((int) artFileChar) - 48;
            multiplyValue *= 10;
            multiplyValue += intValue;
          }
        }
        else {
          if (charCount == 1) {
            if (reoccuringChar != '\0' && artFileChar != '\n') {
              printf("%c", artFileChar);
            }
          }
        }


        reoccuringChar = '\0';
        charCount = 1;
        multiplyValue = 0;
        printf("\n");
      }
    }
  }

  return 0;
}
