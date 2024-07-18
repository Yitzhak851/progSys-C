#include <stdio.h>
#include <string.h>

void swap(int *p_x, int *p_y)
{
    int temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}

int main()
{
    int a = 6, b = 5;
    printf("%d\n", a | b);      // line A
    printf("%d\n", a && b);     // line B
    double d = (a*b)/4;
    printf("%lf\n", d);         // line C

    swap(&a, b);
    printf("%d %d\n", a, b);    // line D

    char arr[] = "Linux C";
    printf("%c\n", arr[2]);      // line E
    printf("%c\n", arr[-2]);     // line F
    arr[1]--;
    printf("%s\n", arr);         // line G

    int l = strlen(arr);
    printf("%d\n", l);           // line H
    l = sizeof(arr);
    printf("%d\n", l);           // line I

    printf("%d\n", 'n'-'m');     // line J

    for ( a = 8; a < 10; a++) { // { isMissing
        for ( b = 6; b < 10; ++b) { // { isMissing
            printf("%d", b);     // line K
        } // } isMissing
    } // } isMissing

    return 0;
}