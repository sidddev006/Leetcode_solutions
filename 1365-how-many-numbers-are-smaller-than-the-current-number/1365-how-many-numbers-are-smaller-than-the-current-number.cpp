class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        unordered_map<int, int> firstIndex; // value -> count of smaller elements
        for (int i = 0; i < n; i++) {
            // only set it the first time we see this value
            if (firstIndex.find(sorted_nums[i]) == firstIndex.end()) {
                firstIndex[sorted_nums[i]] = i;
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = firstIndex[nums[i]];
        }
        return ans;
    }
};