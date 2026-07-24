class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fmax = LLONG_MIN;
        long long smax = LLONG_MIN;
        long long tmax = LLONG_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(fmax == nums[i] || smax == nums[i] || tmax == nums[i]) 
                continue;
            if(nums[i] > fmax){
                tmax = smax;
                smax = fmax;
                fmax = nums[i];
            }
            else if(nums[i] > smax){
                tmax = smax;
                smax = nums[i];
            }
            else if(nums[i] > tmax) tmax = nums[i];
        }
        if(tmax == LLONG_MIN) return fmax;
        else return tmax;
    }
};