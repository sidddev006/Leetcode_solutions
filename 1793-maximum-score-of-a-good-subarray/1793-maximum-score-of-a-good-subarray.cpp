class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k, right = k, mini = nums[k], ans = mini;
        while(left > 0 || right < n-1){
            if(left == 0) right++;
            else if(right == n-1) left--;
            else if(nums[left-1]> nums[right+1]) left--;
            else right++;
            mini = min(mini, min(nums[left], nums[right]));
            ans = max(ans, mini * (right - left+1));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna