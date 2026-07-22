class Solution {
public:
    int maxEle(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++) maxi = max(maxi, nums[i]);
        return maxi;
    }
    long long totalHour(vector<int>& nums, int hours){
        long long tH= 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            //tH += ceil((double) nums[i] / (double) hours);
            tH += (1LL * nums[i] + hours - 1) / hours;
        }
        return tH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxEle(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalH = totalHour(piles, mid);
            if(totalH <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};