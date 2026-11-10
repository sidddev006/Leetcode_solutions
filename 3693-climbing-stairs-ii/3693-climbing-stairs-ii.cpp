class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            int nxt = min({a + 9, b + 4, c + 1}) + costs[i];
            a = b;
            b = c;
            c = nxt;
        }
        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna