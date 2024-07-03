#include <stdio.h>
#include <string.h>

char *getLongestString(char **stringList, int n);

int main(int argc, char **argv) {
   /*** invoke concatStrings on all arguments including argv[0] ***/
   char *longestString = getLongestString(argv, argc); // <-- fix function invocation to ignore program name
   if (argc == 1) {
      printf("Usage: ./<prog-name> <word-1> <word-2> .... ");
      return 1;
   }
   longestString = getLongestString(argv, argc);
   printf("Longest argument is \"%s\"\n", longestString);
   return 0;
}

/****************************************
  * getLongestString - returns a pointer to the longest string
  * in a given array of strings
  * params:
  *- stringList = array of pointres to strings
  *- n = length of array
  * if there is more than one string with the
  * same longest length, returns the one that is first on the list
  *************************************/
char *getLongestString(char **stringList, int n) {
   char *longestString;
   int i;
   int maxLength = strlen(stringList[1]);
   longestString = stringList[1];
   for (i = 2; i < n; i++) {
      /*** after iteration i of the for loop, longestString should hold the longest string among the first i strings in stringlist ***/
      int currerntLength = strlen(stringList[i]);
      if (currerntLength > maxLength) {  
         /*** <-- replace 0 with an appropriate expression  ***/
         longestString = stringList[i];
         maxLength = currerntLength;
         /*** <-- add single expression here ***/
      }
   } // end of for
   return longestString;
}