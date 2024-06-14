#include <stdio.h>

int main() {
   int n1, n2;
   printf ("Input two integer numbers:");
   scanf ("%d%d", &n1, &n2);
   printf ("\nThe sum of the two numbers is:\n");
   printf ("%d+%d=%d\n", n1,n2,n1+n2);
   return 0;
}