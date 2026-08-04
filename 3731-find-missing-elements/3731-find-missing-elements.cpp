class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool cont[101] = {};
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            cont[nums[i]] = true;
        }
        vector<int> ans;
        for(int i = mini+1;i<maxi;i++){
            if(cont[i] == false) ans.push_back(i);
        }
        return ans;
    }
};