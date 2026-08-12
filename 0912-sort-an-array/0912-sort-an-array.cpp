class Solution {
public:
    vector<int> ans;
    void Merge(vector<int>& arr, int low, int mid, int high){
        int left = low, right = mid+1, k = low;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                ans[k] = arr[left];
                left++;
                k++;
            }
            else {
                ans[k] = arr[right];
                right++;
                k++;
            }
        } 
        while(left <= mid){
            ans[k] = arr[left];
            left++;
            k++;
        }
        while(right <= high){
            ans[k] = arr[right];
            right++;
            k++;
        }
        for(int i = low;i<=high;i++){
            arr[i] = ans[i];
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
        ans.resize(n);
        MergeSort(nums, 0, n-1);
        return nums;
    }
};