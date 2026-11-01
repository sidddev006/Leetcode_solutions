class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n =  nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i =0; i+k-1<n;i++){
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna