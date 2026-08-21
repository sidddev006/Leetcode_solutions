class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countLE(vector<int>& coins, long long m) {
        int n = coins.size();
        long long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = __builtin_popcount(mask);
            bool overflow = false;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l = lcm(l, coins[i]);
                    if (l > m) { overflow = true; break; }
                }
            }
            if (overflow) continue;
            if (bits % 2 == 1) total += m / l;
            else total -= m / l;
        }
        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = (long long)k * (*min_element(coins.begin(), coins.end()));
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(coins, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};