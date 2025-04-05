    #include <stdio.h>
// this food return sum of 2 int num
    int sum(int a, int b) {
    return a+b;
    }

    int main() {
    int i,res;
    for(i=0; i<2; i++) {
        int res,a,b;
        scanf("%d%d", &a, &b);
        res = sum(a,b);
        printf("%d + %d = %d\n", a,b,res);
    }
    printf("res = %d\n",res);
    return 0;
    }
