#include <stdio>


int getNextBitPos(int);

int main() {
    int res = getNumPos(14);
    printf("%d\n",res);
    return 0;
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
    /*** last a the function was called with              ***/
    static int last_a   =  0;
    /*** last position that the function returned         ***/
    static int last_pos = -1;
    /***        ADD CODE BELOW THIS POINT                 ***/
    /***        vvvvvvvvvvvvvvvvvvvvvvvvv                 ***/

    if(last_pos == -1 || last_a !=a){
        last_pos = getLSBpos(a);
        last_a = a;
    }
    else if {
        
    }


    /***        ^^^^^^^^^^^^^^^^^^^^^^^^^                 ***/
    /***        ADD CODE ABOVE THIS POINT                 ***/
    return last_pos;
}