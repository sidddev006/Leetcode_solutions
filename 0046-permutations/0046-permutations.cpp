class Solution {
public:
    vector<vector<int>> ans;
    void recurPermute(int ind, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i<nums.size();i++){
            swap(nums[ind], nums[i]);
            recurPermute(ind+1, nums);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        recurPermute(0, nums);
        return ans;
    }
};