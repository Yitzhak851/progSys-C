#include <stdio.h>
int sum (int **a, int nrows, int ncols) {
 int i, j, sum = 0;
 for (i = 0; i < nrows; ++i)
 for (j = 0; j < ncols; ++j)
 sum += a[i][j];
 return sum;
}
int main() {
 int arrayCells[]= {1, 3, 5, 7, 11, 13, 15, 17, 21, 23, 25, 27};
 int* array[] = {arrayCells, arrayCells+4, arrayCells+8};
 printf("Sum of array is: %d\n",sum(array, 3, 4));
 return 0;
}