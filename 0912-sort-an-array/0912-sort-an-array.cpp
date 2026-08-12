class Solution {
public:
    void Merge(vector<int>& arr, int low, int mid, int high){
        int left = low, right = mid+1;
        vector<int> ans;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                ans.push_back(arr[left]);
                left++;
            }
            else {
                ans.push_back(arr[right]);
                right++;
            }
        } 
        while(left <= mid){
            ans.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            ans.push_back(arr[right]);
            right++;
        }
        for(int i = low;i<=high;i++){
            arr[i] = ans[i-low];
        }
    }
    void MergeSort(vector<int>& arr, int low, int high){
        if(low >= high) return;
        int mid = low+ (high - low)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        MergeSort(nums, 0, n-1);
        return nums;
    }
};