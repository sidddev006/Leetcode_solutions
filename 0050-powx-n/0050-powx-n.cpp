class Solution {
public:
// if n is negative, then whatever the answer comes divide it by one
// otherwise if n is positive than just multiply the number n number of times
    double power(double x, long long n){
        if(n==0) return 1;
        double half = power(x, n/2);
        if(n %2 == 0) return half * half;
        return x* half*half;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) return 1.0/power(x, -N);
        return power(x, N);
    }
};