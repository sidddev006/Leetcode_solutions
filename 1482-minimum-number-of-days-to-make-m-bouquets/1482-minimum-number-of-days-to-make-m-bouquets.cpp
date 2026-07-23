class Solution {
public:
    vector<int> maxmin(vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return {mini, maxi};
    }
    bool possible(vector<int>& bloom, int day, int m, int k){
        int cnt = 0, nD = 0;
        for(int i = 0;i<bloom.size();i++){
            if(bloom[i] <= day) cnt++;
            else{
                nD += (cnt/k);
                cnt = 0;
            }
        }
        nD += (cnt/k);
        return nD >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k >n) return -1;
        vector<int> mm = maxmin(bloomDay);
        int low = mm[0], high = mm[1];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(bloomDay, mid, m, k) == true) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};