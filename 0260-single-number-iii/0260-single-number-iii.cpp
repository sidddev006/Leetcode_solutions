class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        map<int, int> mpp;
        for(int i = 0;i<n;i++) mpp[nums[i]]++;
        int count = 0;
        for(auto it: mpp){
            if(it.second == 1){
                ans[count] = it.first;
                count++;
            }
        }
        return ans;
    }
};