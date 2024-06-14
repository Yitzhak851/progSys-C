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

int getLSBpos(int);
int getMSBpos(int);
int getNumPos(int);
int getNextBitPos(int);
void printBP(int);


/*****************************************/
/**    MAIN FUNCTION DEFINITION         **/
/*****************************************/



int main() {

   /***         USE THIS CODE FOR TESTING     ***/
   /***     YOU MAY ALSO ADD MORE TESTS HERE  ***/
   /***      AND MODIFY FUNCTION AS YOU WISH  ***/
#ifdef TEST_1
   printf("Tests for getLSBpos:\n");
   printf("Tests for getLSBpos:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("getLSBpos(%8d) = %3d\n", 4 , getLSBpos( 4));
   printf("getLSBpos(%8d) = %3d\n", 24, getLSBpos(24));
   printf("getLSBpos(%8d) = %3d\n", 0 , getLSBpos( 0));
   printf("getLSBpos(0x%06x) = %3d\n", 0xA00B, getLSBpos(0xA00B));
   printf("getLSBpos(0x%06x) = %3d\n", 0xA6C0, getLSBpos(0xA6C0));
   printf("getLSBpos(%8d) = %3d\n", -1, getLSBpos(-1));
   printf("getLSBpos(%8d) = %3d\n", -24, getLSBpos(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_2
   printf("\nTests for getMSBpos:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("getMSBpos(%3d) = %3d\n",  4, getMSBpos( 4));
   printf("getMSBpos(%3d) = %3d\n", 24, getMSBpos(24));
   printf("getMSBpos(%3d) = %3d\n",  0, getMSBpos( 0));
   printf("getMSBpos(0x%06x) = %3d\n", 0xA00B, getMSBpos(0xA00B));
   printf("getMSBpos(0x%06x) = %3d\n", 0xA6C0, getMSBpos(0xA6C0));
   printf("getMSBpos(%3d) = %3d\n", -1, getMSBpos(-1));
   printf("getMSBpos(%3d) = %3d\n", -24, getMSBpos(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_3
   printf("\nTests for getMSBpos:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("getNumPos(%3d) = %3d\n",  4, getNumPos( 4));
   printf("getNumPos(%3d) = %3d\n", 24, getNumPos(24));
   printf("getNumPos(%3d) = %3d\n",  0, getNumPos( 0));
   printf("getNumPos(0x%06x) = %3d\n", 0xA00B, getNumPos(0xA00B));
   printf("getNumPos(0x%06x) = %3d\n", 0xA6C0, getNumPos(0xA6C0));
   printf("getNumPos(%3d) = %3d\n", -1, getNumPos(-1));
   printf("getNumPos(%3d) = %3d\n", -24,getNumPos(-24));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_4
   printf("\nTests for getNextBitPos:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   int i=1;
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_5
   printf("\nTests for Problem 2.5:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("printBP(%3d):\n",  44);
   printBP(44);
   printf("printBP(%3d):\n",   6);
   printBP( 6);
   printf("printBP(%3d):\n",   0);
   printBP( 0);
   printf("printBP(%3d):\n",  -1);
   printBP(-1);
   printf("getNextBitPos(%3d) = %3d\n", 44,getNextBitPos(44));
   printf("printBP(%3d) (after calling getNextBitPos):\n",  44);
   printBP(44);
#endif

   return 0;

}

