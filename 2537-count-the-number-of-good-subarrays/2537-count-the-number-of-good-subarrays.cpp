class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long pairs = 0, ans = 0;
        int l = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            pairs += freq[nums[r]]++;
            while (pairs >= k) {
                freq[nums[l]]--;
                pairs -= freq[nums[l]]; // pairs lost by removing nums[l]
                l++;
            }
            ans += l; // starts 0..l-1 give good subarrays ending at r
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna