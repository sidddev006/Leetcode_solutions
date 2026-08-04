class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        vector<int> ans;
        for(int i = mini; i<maxi;i++){
            if(mpp[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};