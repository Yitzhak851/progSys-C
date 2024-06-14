#include <stdio.h>

int main (int argc, char *argv[]) {
   int   i;

   printf("There are %d elements in the array:\n", argc);
   for(i=0; i<argc; i++) {
     printf("argv[%d] = %s\n",i, argv[i]);
   }
   return 0;
}