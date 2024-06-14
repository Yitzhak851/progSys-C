#include <stdio.h>

double div(double a, double b) {
    return a/b;
}

int main() {
    int i,res;
    for(i=0; i<2; i++) {
        int a,b; double res;
        scanf("%d%d", &a, &b);
        res = div(a,b);
        printf("%d / %d = %lf\n", a,b,res);
    }
    printf("res = %d\n",res);
    return 0;
}
