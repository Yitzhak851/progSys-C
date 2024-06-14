/* Left and right cyclic shifts in a given value by a given number of bit positions */

#include <stdio.h>

int fibo();
int circleShiftLeft(int value, int spins);
int circleShiftRight(int value, int spins);
void displayBits(int value);

int main()
{
        int choice, result, value, i, n;

        while (1)
        {
                printf("\nEnter Options (1 - Fibonacci, 2 - LeftShift, 3 - rightShigt, other - Exit): ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1: printf("How many times call Fibonacci? ");
                        scanf("%d", &n);

                        for (i = 0; i < n; i++)
                                printf("%2d ", fibo());
                        printf("\n");
                        break;

                case 2: printf("Enter value: ");
                        scanf("%d", &value);
                        printf("Enter number of bits for shift: ");
                        scanf("%d", &n);

                        printf("\nBefore cyclic shifting\n");
                        displayBits(value);
                        result = circleShiftLeft(value, n);
                        printf("After cyclic shifting\n");
                        displayBits(result);
                        break;

                case 3: printf("Enter value: ");
                        scanf("%d", &value);
                        printf("Enter number of bits for shift: ");
                        scanf("%d", &n);

                        printf("\nBefore cyclic shifting\n");
                        displayBits(value);
                        result = circleShiftRight(value, n);
                        printf("After cyclic shifting\n");
                        displayBits(result);
                        break;

                        default: return 0;
                }
        }
}

int fibo()
{
        /* Code goes here */
        return 0;
}

int circleShiftLeft(int value, int bits_num)
{
        /* Code goes here */
        return value;
}


int circleShiftRight(int value, int bits_num)
{
        /* Code goes here */
        return value;
}


void displayBits(int value)
{
        int c; /* counter */
        int bits = sizeof(int) * 8; /* total bits in int*/
        /* declare displayMask and left shift 31 bits */
        unsigned displayMask = 1 << (bits - 1);

        printf("%10d = ", value);

        /* loop through bits */
        for (c = 1; c <= bits; c++) {
                putchar(value & displayMask ? '1' : '0');
                value <<= 1; /* shift value left by 1 */

                if (c % 8 == 0) { /* output a space after 8 bits */
                        putchar(' ');
                } /* end if */

        } /* end for */

        putchar('\n');
} /* end function displayBits */

