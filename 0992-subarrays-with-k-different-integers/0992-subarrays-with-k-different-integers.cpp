class Solution {
public:
    int atMost(vector<int>&nums, int k){
        int n = nums.size();
        vector<int>freq(n+1, 0);
        int left = 0, distinct =0, res = 0;
        for(int right =0; right<n;right++){
            if(freq[nums[right]]++ == 0) distinct++;
            while(distinct > k){
                if(--freq[nums[left]] == 0) distinct--;
                left++;
            }
            res += right - left+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna