class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i = 0; i<k;i++) sum += nums[i];
        double MaxAvg = sum/k;
        for(int right = k; right < n;right ++){
            sum += nums[right];
            sum -= nums[right - k];
            MaxAvg = max(MaxAvg, sum/k);
        }
        return MaxAvg;
    }
};