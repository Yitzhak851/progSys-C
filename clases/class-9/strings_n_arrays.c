#include<stdio.h>
#include <string.h>

int main() {
   char str1[10] = "hello";
   char str2[10] = {'h','e','l','l','o'};
   char str3[]   = "hello";
   char *str4    = "hello";

   printf("sizeof(str1)=%ld, strlen(str1)=%ld\n",sizeof(str1),strlen(str1));
   printf("sizeof(str2)=%ld, strlen(str2)=%ld\n",sizeof(str2),strlen(str2));
   printf("sizeof(str3)=%ld, strlen(str3)=%ld\n",sizeof(str3),strlen(str3));
   printf("sizeof(str4)=%ld, strlen(str4)=%ld\n",sizeof(str4),strlen(str4));
   printf("sizeof(str1 + 2)=%ld, strlen(str1 + 2)=%ld\n",sizeof(str1+2),strlen(str1+2));

   return 0;
}
