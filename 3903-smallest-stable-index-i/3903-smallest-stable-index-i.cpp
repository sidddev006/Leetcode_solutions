class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // instability score -> *max_element(nums.begin(), nums+i) - *min_element(nums+i, nums.end());
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i <n;i++){
            int instability_score = *max_element(nums.begin(), nums.begin()+i+1) - *min_element(nums.begin()+i, nums.end());
            if(instability_score <= k) return i;
        }
        return -1;
    }
};