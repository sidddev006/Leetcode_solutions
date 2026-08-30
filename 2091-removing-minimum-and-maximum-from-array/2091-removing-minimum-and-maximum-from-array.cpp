class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int min_index = -1;
        int max_index = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =0; i<n;i++){
            if(nums[i] < mini){
                mini = nums[i];
                min_index = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                max_index = i;
            }
        }
        int i = min(min_index, max_index);
        int j = max(min_index, max_index);
        int fromFront = j+1;
        int fromBack = n - i;
        int fromBoth = (i+1) + (n-j);
        return min({fromFront, fromBack, fromBoth});
    }
};