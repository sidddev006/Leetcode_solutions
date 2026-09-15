class Solution {
public:
    vector<vector<int>>answers;
    void subsets(vector<int>& nums, int n, int ind, vector<int>& curr_subset){
        if(ind == n){
            answers.push_back(curr_subset);
            return;
        }
        curr_subset.push_back(nums[ind]);
        subsets(nums, n, ind+1, curr_subset);
        curr_subset.pop_back();
        int next = ind+1;
        while(next < n && nums[next] == nums[ind]) next++;
        subsets(nums, n, next, curr_subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>curr_subset;
        subsets(nums, nums.size(), 0, curr_subset);
        return answers;
    }
};