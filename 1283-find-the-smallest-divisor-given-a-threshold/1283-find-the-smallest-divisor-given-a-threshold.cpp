class Solution {
public:
    bool calcthres(vector<int>& nums, int val, int threshold){
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n;i++){
            //sum+= ceil((double)nums[i] / val);
            sum += 1LL * (nums[i]+ val - 1)/val;
            if(sum > threshold) return false;
        }
        return sum <= threshold;
    }
    int maximum(vector<int>& nums){
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = maximum(nums);
        while(low <= high){
            int mid = low + (high - low )/2;
            if(calcthres(nums, mid, threshold) == true) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};