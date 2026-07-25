class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);
        vector<int> ans(n, 1);
        int suffix = 1, prefix = 1;
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1] * nums[i - 1];
        }
        for(int j = n-2;j>=0;j--){
            suff[j] = suff[j+1] * nums[j + 1];
        }
        for(int i = 0;i<n;i++){
            ans[i] = pref[i] * suff[i];
        }
        return ans;
    }
};