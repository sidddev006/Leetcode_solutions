class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];
        int total = 0;
        for(int a: nums){
            curMax = max(curMax+a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin+a, a);
            minSum = min(minSum,curMin);
            total +=a ;
        }
        if(maxSum < 0) return maxSum;
        else return max(maxSum, total - minSum);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna