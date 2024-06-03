#include <stdio.h>

int main() {
  char    string[15] = "Hello world";
  short*  shortP;
  int*    intP;
  double* doubleP;

  /*** print first two chars in array ***/
  printf("First char = '%c', second char = '%c'\n", string[0], string[1]);
  /*** print first two chars in array as ASCII code ***/
  printf("First char = %d, second char = %d\n", string[0], string[1]);
  /*** pointer types do not freely convert. Will trigger warning ***/
  shortP = string;
  printf("First short = %d, second short = %d\n", shortP[0], shortP[1]);
  /*** casting will prevent type conversion warning ***/
  intP = (int*)string;
  printf("First int = %d, second int = %d\n", intP[0], intP[1]);
  /*** floating point representation with 8 bytes ***/
  doubleP = (double*)string;
  printf("First double = %g, second double = %g\n", doubleP[0], doubleP[1]);

  return 0;
}
