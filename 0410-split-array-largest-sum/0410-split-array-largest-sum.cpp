class Solution {
public:
    bool possible(vector<int>& arr, int mid, int k){
        long long sum = 0, splits = 1;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(sum + arr[i] <= mid) sum+= arr[i];
            else{
                splits++;
                sum = arr[i];
            }
        }
        return splits <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(nums, mid, k) == true) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};