    #include <stdio.h>
    // 0: f1() returns 101
    // 1: f1() returns   2
    // 2: f1() returns  11
    //--------------------
    // 0: f1() returns   1
    // 1: f1() returns   2
    // 2: f1() returns   3
    //--------------------
    // 0: f1() returns  11
    // 1: f1() returns  12
    // 2: f1() returns  13
    int num = 1;
    int f1() {
        int num = 100;
        num++;
        return num;
    }
    int f2() {
        num++;
        return num;
    }
    int f3() {
        static int num = 10;
        num++;
        return num;
    }
    int main() {
        int i;
        for(i=0; i<3; i++) {
            printf("%2d: f1() returns %3d\n", i, f1());
            printf("%2d: f2() returns %3d\n", i, f2());
            printf("%2d: f3() returns %3d\n", i, f3());
        }
        return 0;
    }