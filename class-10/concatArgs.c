#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*** FUNCTION DECLARATIONS ***/
char* strdup(const char* source);
char* strattach(const char* str1, const char* str2);


int main (int argc, char** argv) {
  int i;
  char *concat_args;

  /** first argument is the separator **/
  if(argc < 2) {
    printf("Expecting at least one argument with separator.\n");
    printf("Usage: %s <separator> [word1 word2 ... ]\n",argv[0]);
    return 1;
  }

  /** no args - print nothing and return **/
  if(argc == 2) {
    return 0;
  }

  /*** duplicate first arg (argv[2]) into dynamically allocated string **/
  concat_args = strdup(argv[2]);

  /** attach args 3..argc-1 one by one **/
  for(i=3; i<argc; i++) {    // argv[1] is first argument
    /** attach separator     **/
    concat_args = strattach(concat_args, argv[1]);
    /** attach i'th argument **/
    concat_args = strattach(concat_args, argv[i]);
  }
  printf("%s\n", concat_args);
  free(concat_args);

  return 0;
}

char* strdup(const char* source) {

  char* newString;
  newString = malloc(1+strlen(source));
  if(!newString) return NULL;
  strcpy(newString, source);
  return newString;

}


char* strattach(const char* str1, const char* str2) {

  char* newString = malloc(1 + strlen(str1) + strlen(str2));
  if(!newString) return NULL;
  strcpy(newString, str1);
  strcat(newString, str2);
  return newString;

}