#include <stdio.h>

// return string length
int my_strlen(const char*);
// copy string into buffer
char* my_strcpy(char* dest, const char* source);
// concat string after other string
char* my_strcat(char* dest, const char* source);

int main() {
   char sentence[50] = "hello";
   char* world = "world";
   printf("sentence before: %s\n",sentence);
   my_strcat(sentence," ");
   my_strcat(sentence,world);
   printf("sentence after:  %s\n",sentence);
   return 0;
}

/*****************************
  my_strlen
  returns string length (not including terminating '\0'
  param:
  - str - string pointer
  return:
  - number of characters from pointed char to first '\0'
  ***************************/

int my_strlen(const char* str) {
   int len=0;
   while(str[len++])
                 ;
   return len-1;
}


/*****************************
  my_strcpy
  copies string into a given array buffer
  assumes that array has sufficient space to contain string (including terminating '\0')
  param:
  - dest - destination buffer
  - source - string pointer for source string
  return:
  - pointer to destination string (equal to original dest)
  ***************************/
char* my_strcpy(char* dest, const char* source) {
   int i=0;
   while(source[i]) {
      dest[i] = source[i];
      i++;
   }
   dest[i] = '\0';
   return dest; // return pointer to dest string
}

/*****************************
  my_strcat
  concattenates string after a given string in a given array buffer
  assumes that array has sufficient space to contain both strings (including terminating '\0')
  param:
  - dest - destination buffer
  - source - string pointer for source string
  return:
  - pointer to destination string (equal to original dest)
  ***************************/
char* my_strcat(char* dest, const char* source) {
   /*** WRITE CODE HERE ***/
   return dest;  // return pointer to dest string
}

