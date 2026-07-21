class Solution {
public:
    int first(vector<int>& nums, int target, int n){
        int low = 0, high = n -1, first = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]== target){
                first = mid;
                high = mid - 1; // go towards left side
            }
            else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return first;
    }
    int last(vector<int>& nums, int target, int n){
        int low = 0, high = n -1, last = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]== target){
                last = mid;
                low = mid + 1; // go towards right side
            }
            else if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {first(nums, target, n), last(nums, target, n)};
    }
};