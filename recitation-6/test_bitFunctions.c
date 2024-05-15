#include <stdio.h>

/*************************************************
*  test_bitPositions.c
*  -------------------
*  A program for testing bit position functions
*  from bitPositions.c
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! YOU MAY ADD MORE TESTS !!                 */
/************************************************/

/*****************************************/
/**    EXTERNAL FUNCTION DECLARATIONS   **/
/*****************************************/

int countBits(int);
int numLength(int);
int longestSequence(int);

/*****************************************/
/**    MAIN FUNCTION DEFINITION         **/
/*****************************************/



int main() {

   /***         USE THIS CODE FOR TESTING     ***/
   /***     YOU MAY ALSO ADD MORE TESTS HERE  ***/
   /***      AND MODIFY FUNCTION AS YOU WISH  ***/
#ifdef TEST_1

   printf("Tests for countBits:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("countBits(%8d) = %3d\n", 4 , countBits( 4));
   printf("countBits(%8d) = %3d\n", 24, countBits(24));
   printf("countBits(%8d) = %3d\n", 0 , countBits( 0));
   printf("countBits(0x%06x) = %3d\n", 0xA00B, countBits(0xA00B));
   printf("countBits(0x%06x) = %3d\n", 0x17F3220A, countBits(0x17F3220A));
   printf("countBits(%8d) = %3d\n", -1, countBits(-1));
   printf("countBits(%8d) = %3d\n", -24, countBits(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_2
   printf("\nTests for numLength:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("numLength(%3d) = %3d\n",  4, numLength( 4));
   printf("numLength(%3d) = %3d\n", 24, numLength(24));
   printf("numLength(%3d) = %3d\n",  0, numLength( 0));
   printf("numLength(0x%06x) = %3d\n", 0xA00B, numLength(0xA00B));
   printf("numLength(0x%06x) = %3d\n", 0x17F3220A, numLength(0x17F3220A));
   printf("numLength(%3d) = %3d\n", -1, numLength(-1));
   printf("numLength(%3d) = %3d\n", -24, numLength(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_3
   printf("\nTests for longestSequence:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("longestSequence(%3d) = %3d\n",  4, longestSequence( 4));
   printf("longestSequence(%3d) = %3d\n", 24, longestSequence(24));
   printf("longestSequence(%3d) = %3d\n",  0, longestSequence( 0));
   printf("longestSequence(0x%06x) = %3d\n", 0xA00B, longestSequence(0xA00B));
   printf("longestSequence(0x%06x) = %3d\n", 0x17F3220A, longestSequence(0x17F322>
   printf("longestSequence(%3d) = %3d\n", -1, longestSequence(-1));
   printf("longestSequence(%3d) = %3d\n", -24,longestSequence(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

   return 0;

}

