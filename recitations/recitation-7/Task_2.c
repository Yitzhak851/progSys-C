#include <stdio>


int getMSBpos(int a);

int main() {
    int res = getNumPos(14);
    printf("%d\n",res);
    return 0;
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