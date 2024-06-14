    #include <stdio.h>
    /********************************
    This is a C program for computing
    an integer power of a real number
    *******************************/
    /*** function declarations ***/
    // computes power - x^n
    double power(double, int);
    // computes square - x^2
    double square(double);
   /*** global variables ***/
    int function_counter = 0;    // computes number of function invocations
    /*** main ***/
    int main() {
    double x, res;
    int n, status;
    printf("Please enter a real number (x) followed by an integer (n), and program will compute power x^n:\n");
    status = scanf("%lf %d", &x, &n);
    if(status < 2) {
        printf("Faulty input. Expecting a real number (x) followed by an integer (n).\n");
        return 1;
    }
    res = power(x,n);
    printf("%lf^%d = %lf\n",x,n,res);
    return 0;
    }
    /*** end of main() ***/
    /************************************
    function power
    params:
    - x - real number (base)
    - n - integer number (exponent)
    recursive function for computing power. Uses the fact that x^n = (x^(n/2))^2.
    base case: n=0 ==> x^n=1.0
    return value: x^n
    ***********************************/
    double power(double x, int n) {
    double y = 1.0;
    function_counter++;
    if(n < 0) {
        //if n<0, compute using absolute value for exponent and take inverse
        y = 1 / power(x,-n);
    } else if(n>0) {
        // if n is even, then x^n = (x^(n/2))^2
        // if n is odd.  then x^n = x*(x^(n/2))^2  (because (n/2)*2 = n-1)
        y = square(power(x,n/2));
        if(n%2 == 1) y = y*x;
    }
    // base of recursion: n=0
    return y;
    }
    /*** end of power ***/
    /************************************
    function square
    params:
    - x - real number
    return value: x^2
    ***********************************/
    double square(double x) {
    function_counter++;
    return x*x;
    }
