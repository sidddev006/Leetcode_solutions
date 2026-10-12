class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int cnt[30] = {0};

        // Step 1: count how many numbers have each bit set
        for (int x : nums) {
            for (int b = 0; b < 30; b++) {
                if ((x >> b) & 1) cnt[b]++;
            }
        }

        // Step 2: build the k biggest numbers greedily
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            for (int b = 0; b < 30; b++) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b);   // give this number bit b
                    cnt[b]--;            // that 1 is now used up
                }
            }
            ans = (ans + (cur * cur) % MOD) % MOD;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna