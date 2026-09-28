class Solution {
public:
    vector<vector<int>> ans;
    void recurPermute(int ind, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;          // values already tried at this position
        for(int i = ind; i < nums.size(); i++){
            if(used.count(nums[i])) continue;   // skip duplicate value
            used.insert(nums[i]);
            swap(nums[ind], nums[i]);
            recurPermute(ind+1, nums);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        recurPermute(0, nums);
        return ans;
    }
};