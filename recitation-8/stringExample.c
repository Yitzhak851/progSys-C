#include <stdio.h>
#include <string.h>

#define ARRSIZE 15

int main() {
  char buffer1[ARRSIZE],
       buffer2[ARRSIZE];

  strcpy(buffer1, "Hello");
  printf("String  = %s\n", buffer1);
  strcat(buffer1, " World");
  printf("String  = %s\n", buffer1);
  buffer1[4] = '\0';   // buffer1[4]
  printf("String  = %s\n", buffer1);
  strcat(buffer1,"o you");
  printf("String  = %s\n", buffer1);
  strcpy(buffer2,buffer1);
  printf("String1 = %s\n", buffer1);
  printf("String2 = %s\n", buffer2);
  strcat(buffer1,buffer1);
  printf("String1 = %s\n", buffer1);
  printf("String2 = %s\n", buffer2);
  return 0;
}
