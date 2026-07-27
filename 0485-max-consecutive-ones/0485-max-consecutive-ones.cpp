class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1) count++;
            else{
                maxi = max(maxi, count);
                count = 0;
            }
        }
        maxi = max(count, maxi);
        return maxi;
    }
};