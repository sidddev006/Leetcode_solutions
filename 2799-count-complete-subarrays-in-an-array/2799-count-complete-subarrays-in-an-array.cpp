class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int total = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int,int> freq;
        int ans = 0, l = 0;
        for (int r = 0; r < n; r++) {
            freq[nums[r]]++;
            while ((int)freq.size() == total) {
                if (--freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            ans += l; // starts 0..l-1 give complete subarrays ending at r
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna