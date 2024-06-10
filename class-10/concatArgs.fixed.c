#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*** FUNCTION DECLARATIONS ***/
char* strdup(const char* source);
char* strattach(const char* str1, const char* str2);


int main (int argc, char** argv) {
  int i;
  char *concat_args, *new_concat_args;

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
  if(!concat_args) {         // <-- need to check return value of every function that allocates memory
    printf("Out of memory when allocating space for first argument %s.\n",argv[1]);
    return 2;                // <-- exit status for memory allocation issues
  }

  /** attach args 3..argc-1 one by one **/
  for(i=3; i<argc; i++) {    // argv[1] is first argument
    /** attach separator     **/
    // concat_args = strattach(concat_args, argv[1]);    <-- previous call resulted in leak of memory pointed to by concat_args before call to function
    new_concat_args = strattach(concat_args, argv[1]);
    free(concat_args);       // <-- we need to free the last version of concat_args before we make concat_args point to newly allocated memory
    concat_args = new_concat_args;
    if(!concat_args) {   // <-- need to check return value of every function that allocates memory
      printf("Out of memory when allocating space for separator before %d'th argument %s.\n",i-1, argv[i]);
      return 2;
    }

    /** attach i'th argument **/
    // concat_args = strattach(concat_args, argv[i]);   We apply the same changes to this part of the code
    new_concat_args = strattach(concat_args, argv[i]);
    free(concat_args);
    concat_args = new_concat_args;
    if(!concat_args) {
      printf("Out of memory when allocating space for %d'th argument %s.\n",i-1, argv[i]);
      return 2;
    }

  }
  printf("%s\n", concat_args);
  free(concat_args);       //   <-- final free remains

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
  return newString;

}
