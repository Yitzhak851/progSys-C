#include <stdio.h>

/*************************************************
*  bitPositions.c
*  --------------
*  A program containing functions for determining
*  the bits turned on in the binary
*  representation of integers
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Task 1 - Recitation 06
* computes the LSB of a given number
*********************************/
int getLSBpos(int);

/*********************************
* Task 2 - Recitation 06
* computes the MSB of a given number
*********************************/
int getMSBpos(int);

/*********************************
* Task 3 - Recitation 06
* computes number of bits turned on
* in the binary representation
* of a given number
*********************************/
int getNumPos(int);
/*********************************
* Task 4 - Recitation 07
* computes the next bit turned on
* in the binary representation
* of a given number
*********************************/
int getNextBitPos(int);

/*********************************
* Task 5 - Recitation 07
* prints all bit positions turned on
* in the binary representation
* of a given number
*********************************/
void printBP(int);


/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/


/*********************************
* Task 1 - Recitation 06
* computes the LSB of a given number
* param:
* a (int)
* returns the LSB of a
*********************************/
int getLSBpos(int a) {
   if(1) {               /*** <--- replace 1 with appropriate expression    ***/
      return -1;
   }
   if(1) {               /*** <--- replace 1 with appropriate expression. Use onl>
      return 0;
   }
   return 0;             /*** <--- replace 0 with appropriate expression. Use a r>
}

/*********************************
* Task 2 - Recitation 06
* computes the MSB of a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getMSBpos(int a)  {
   if(1) {               /*** <--- replace 1 with appropriate expression.    ***/
      return -1;
   }
   return 0;             /*** <--- replace 0 with appropriate expression. Use a r>
}

/*********************************
* Task 3 - Recitation 06
* computes the number of bits
* turned on in a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getNumPos(int a)  {
   if(1) {               /*** <--- replace 1 with appropriate expression.    ***/
      return 0;
   }
   return 0;             /*** <--- replace 0 with appropriate expression. Use a r>
}


/*********************************
* Task 4 - Recitation 07
* computes the next bit turned on
* in the binary representation
* of a given number
* param:
* a (int)
* if parameter a equals the last number that the function was called with,
* then return the next bit position in bp(a).
* if previous bit position was the MSB, then reutrn -1.
* if parameter a is differnt from the last number that the function was called wi>
* or the last position returned was -1, then return the LSB.
*********************************/
int getNextBitPos(int a) {
   /*** Problem 2.3:                                     ***/
   /*** last a the function was called with              ***/
   static int last_a   =  0;
   /*** last position that the function returned         ***/
   static int last_pos = -1;

   /***        ADD CODE BELOW THIS POINT                 ***/
   /***        vvvvvvvvvvvvvvvvvvvvvvvvv                 ***/

   /***        ^^^^^^^^^^^^^^^^^^^^^^^^^                 ***/
   /***        ADD CODE ABOVE THIS POINT                 ***/

   return last_pos;
}

/*********************************
* Task 5 - Recitation 07
* prints all bit positions turned on
* in the binary representation
* of a given number
* param:
* a (int)
* uses the following format: bp(a) = pos1 pos2 ...
* there should be a single space character between every two positions
* and a newline should be printed in the end.
*********************************/
void printBP(int a){
   /***        ADD CODE BELOW THIS POINT                 ***/
   /***        vvvvvvvvvvvvvvvvvvvvvvvvv                 ***/

   /***        ^^^^^^^^^^^^^^^^^^^^^^^^^                 ***/
   /***        ADD CODE ABOVE THIS POINT                 ***/
   return;
}



