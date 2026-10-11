class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;
        for(int n: nums) if(n < pivot) ans.push_back(n);
        for(int n: nums) if(n == pivot) ans.push_back(n);
        for(int n: nums) if(n > pivot) ans.push_back(n);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna