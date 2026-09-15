class Solution {
public:
    const long long MOD = 1e9+7;
    long long power(long long x, long long n){
        if(n==0) return 1;
        long long half = power(x, n/2);
        half = (half*half)%MOD;
        if(n%2 == 0) return half;
        else return (half*x)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;
        long long result = (power(5, evenCount) * power(4, oddCount))%MOD;
        return (int)result;
    }
};