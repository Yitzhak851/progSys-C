#include <stdio>


int getLSBpos(int a);

int main() {
    int res = getNumPos(14);
    printf("%d\n",res);
    return 0;
}

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