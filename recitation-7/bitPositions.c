#include <stdio.h>
/*************************************************
*  bitPositions.c
*  --------------
*  A program containing functions for determining
*  the bits turned on in the binary
*  representation of integers
*************************************************/

/********************************/
/**    FUNCTION Decleration    **/
/********************************/

/*********************************
* Task 1 - Recitation 06
* computes the LSB of a given number
*********************************/
int getLSBpos(int a);

/*********************************
* Task 2 - Recitation 06
* computes the MSB of a given number
*********************************/
// bp(a)={i|a_i = 1}
// bp(4)={1,0,0}     => {2}
// bp(13)={1,1,0,1}  => {0,2,3}
// bp(24)={1,1,0,0,0}  => {3,4}
// getMSBpos(4)      => returns 2
// getMSBpos(13)     => returns 3
// getMSBpos(24)     => returns 4
int getMSBpos(int a);

/*********************************
* Task 3 - Recitation 06
* computes number of bits turned on
* in the binary representation
* of a given number
*********************************/
// bp(4)={1,0,0}     => {2}
// bp(13)={1,1,0,1}  => {0,2,3}
// bp(24)={1,1,0,0,0}  => {3,4}

// getMSBpos(4)      => returns 1
// getMSBpos(13)     => returns 3
// getMSBpos(24)     => returns 2
int getNumPos(int a);

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
   if(!a){                    //*** <--- replace 1 with appropriate expression    ***/
      return -1;
   }
   if(a&1){                   //*** <--- replace 1 with appropriate expression. Use onl>
      return 0;
   }
   return 1 + getLSBpos(a>>1); //*** <--- replace 0 with appropriate expression. Use a r>
}

/*********************************
* Task 2 - Recitation 06
* computes the MSB of a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getMSBpos(int a) {
   if(!a){           // /*** <--- replace 1 with appropriate expression.    ***/
      return -1;
   }
   return 1 + getMSBpos((unsigned)a>>1); // /*** <--- replace 0 with appropriate expression. Use a r>
}

/*********************************
* Task 3 - Recitation 06
* computes the number of bits
* turned on in a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getNumPos(int a){
   if(a==0){      // /*** <--- replace 1 with appropriate expression.    ***/
      return 0;
   }
   return (a&1) + getNumPos((unsigned)a>>1);  // /*** <--- replace 0 with appropriate expression. Use a r>
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



