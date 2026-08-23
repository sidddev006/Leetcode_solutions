class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2); // 0- number that appears twice, 1-number that is missing
        unordered_map<int, int> mpp;
        for(int num: nums) mpp[num]++;
        for(int i = 1; i<=n;i++){
            if(mpp[i] > 1) ans[0] = i;
            if(mpp[i] == 0) ans[1] = i;
        }
        return ans;
    }
};