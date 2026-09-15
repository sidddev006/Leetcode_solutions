class Solution {
public:
    vector<vector<int>>answers;
    void calc_combination(vector<int>& nums, int n, int ind, int target, vector<int>& curr){
        if(target == 0){
            answers.push_back(curr);
            return;
        }
        if(ind == n || target < 0) return;
        curr.push_back(nums[ind]);
        calc_combination(nums, n, ind, target - nums[ind], curr);
        curr.pop_back();
        calc_combination(nums, n, ind+1, target, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>curr;
        calc_combination(candidates, n, 0, target, curr);
        return answers;
    }
};