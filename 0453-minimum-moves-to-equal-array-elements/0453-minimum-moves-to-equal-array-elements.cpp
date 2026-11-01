class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum  = accumulate(nums.begin(), nums.end(), 0LL);
        int mini = *min_element(nums.begin(), nums.end());
        return sum - (nums.size() *mini);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna