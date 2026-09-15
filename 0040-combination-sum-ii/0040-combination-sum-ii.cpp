class Solution {
public:
    vector<vector<int>>answers;
    void calc_combination(vector<int>& nums, int n, int ind, int target, vector<int>curr){
        if(target == 0){
            answers.push_back(curr);
            return;
        }
        if(ind == n || target < 0 || nums[ind] > target) return;
        curr.push_back(nums[ind]);
        calc_combination(nums, n, ind+1, target-nums[ind], curr);
        curr.pop_back();
        int next = ind+1;
        while(next < n && nums[ind] == nums[next]) next++;
        calc_combination(nums, n, next, target, curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>curr;
        calc_combination(nums, n, 0, target, curr);
        return answers;   
    }
};