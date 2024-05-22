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
// bp(a)={i|a_i = 1}
// bp(4)={1,0,0}     => {2    }
// bp(13)={1,1,0,1}  => {0,2,3}
// bp(24)={1,1,0,0,0}=> {3,4  }
// getLSBpos(4)      => returns 2
// getLSBpos(13)     => returns 0
// getLSBpos(24)     => returns 3
*********************************/
int getLSBpos(int a) {
    if(a==0){                    //*** <--- replace 1 with appropriate expression    ***/
        return -1;
    }
    if(a&1){                   //*** <--- replace 1 with appropriate expression. Use onl>
        return 0;
    }
    return 1 + getLSBpos(a>>1); //*** <--- replace 0 with appropriate expression. Use a r>
}