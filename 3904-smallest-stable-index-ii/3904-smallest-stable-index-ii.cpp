class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // run a suffix min and prefix max array and then whose prefix max - suffix min will be <= k it will be the answer
        vector<int> suff_min(n);
        suff_min[n-1] = nums[n-1]; // assigning the last element to suff_min so i have some ground to cover
        for(int i = n-2; i>=0;i--){
            suff_min[i] = min(suff_min[i+1], nums[i]); // checking whether the previous element is smaller than the current element
        }
        int curr_max = INT_MIN; // declaring a variable for the current maximum
        for(int i = 0; i < n; i++){
            curr_max = max(curr_max, nums[i]); // computing the current maximum
            if(curr_max - suff_min[i] <= k) return i; // checking whether the current maximum - suffix_minimum is lesser than equal to k
        }
        return -1; // returning -1 if no smallest stable index is present
    }
};