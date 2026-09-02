class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] == target){
                ans = min(ans, abs(i-start));
            }
        }
        return ans;
    }
};