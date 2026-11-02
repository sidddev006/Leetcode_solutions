class Solution {
public:
    int helper(vector<int>&nums, int target, vector<int>&temp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(temp[target] != -1) return temp[target];
        int count = 0;
        for(auto num: nums){
            count += helper(nums, target-num, temp);
        }
        return temp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target +1, -1);
        return helper(nums, target, memo);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna