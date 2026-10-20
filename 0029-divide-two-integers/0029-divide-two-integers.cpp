class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor >= 0) sign = false;
        long long  a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long ans = 0;
        while(a >= b){
            long long cnt = 0;
            while(a >= (b << (cnt+1))) cnt++;
            ans += (1LL << cnt);
            a-= (b << cnt);
        }
        return sign? ans: -ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna