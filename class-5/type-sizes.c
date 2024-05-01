#include <stdio.h>

int main() {
    printf ("         char:%3lu\n\n",sizeof(char));
    printf ("        short:%3lu\n",sizeof(short));
    printf ("          int:%3lu\n",sizeof(int));
    printf ("     unsigned:%3lu\n",sizeof(unsigned));
    printf ("         long:%3lu\n",sizeof(long));
    printf ("    long long:%3lu\n\n",sizeof(long long));
    printf ("        float:%3lu\n",sizeof(float));
    printf ("       double:%3lu\n",sizeof(double));
    printf ("  long double:%3lu\n",sizeof(long double));

    return 0;
}