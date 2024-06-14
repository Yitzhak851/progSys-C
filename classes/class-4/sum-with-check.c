#include <stdio.h>

int main()
{

    int n1, n2, res;

    printf("Input two integer numbers:");
    res = scanf("%d%d", &n1, &n2);
    if (res < 2)
    {
        printf("Wrong input. Expecting two integers.\n");
        return 1;
    }
    printf("\nThe sum of the two numbers is:\n");
    printf("%d+%d=%d\n", n1, n2, n1 + n2);
    return 0;
}
