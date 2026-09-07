class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        // sort indices by value descending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });

        // keep only the top k indices
        idx.resize(k);

        // restore original order
        sort(idx.begin(), idx.end());

        vector<int> ans;
        for (int i : idx) ans.push_back(nums[i]);
        return ans;
    }
};