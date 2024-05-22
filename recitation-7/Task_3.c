#include <stdio>


int getNumPos(int a);

int main() {
    int res = getNumPos(14);
    printf("%d\n",res);
    return 0;
}

int getNumPos(int a){
    if(a==0){
        return 0;
    }
    return (a&1) + getNumPos((unsigned)a>>1);
}