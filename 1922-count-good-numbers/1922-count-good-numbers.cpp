class Solution {
public:
    long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        return (power(5, evenPositions) *
                power(4, oddPositions)) % MOD;
    }
};