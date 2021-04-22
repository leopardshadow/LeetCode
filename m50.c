
#include <stdio.h>


double myPow(double x, int n){
    double ans = 1., cur_x;
    long long m = n;
    if( m < 0) {
        m = -m;
        x = 1/x;
    }
    while(m) {
        if(m & 1)
            ans *= x;
        m = m >> 1;
        x *= x;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    printf("%lf\n", myPow(2.0, 10));
    printf("%lf\n", myPow(2.1, 3));
    printf("%lf\n", myPow(2.0, -2));

    // be aware of edge cases
    printf("%lf\n", myPow(1.0, -2147483648));

    printf("%lf\n", myPow(2.0, -2));

    return 0;
}


/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Pow(x, n).
Memory Usage: 5.5 MB, less than 67.58% of C online submissions for Pow(x, n).
*/