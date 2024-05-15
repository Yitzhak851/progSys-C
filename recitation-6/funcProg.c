#include<stdio.h>

int    divide3(int,int);
int    divide1(int x, int y);
int    divide2(double,double a);
int    divide1(int numerator,int denominator);

int main() {
   printf("divide1(4,3) = %d\n",divide1(4/3));
   printf("divide2(4,3) = %d\n",divide2(4,3));
   printf("divide1(4.0,3.0) = %d\n",divide1(4.0,3.0));
   printf("divide2(4.0,3.0) = %d\n",divide2(4.0,3.0));
   return 0;
}

double divide2(double a, int b) {
   return a/b;
}

int divide1(int a, int b) {
   return a/b;
}
