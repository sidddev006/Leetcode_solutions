class Solution {
public:
    vector<int> result;
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high){
        vector<pair<int,int>> temp;
        int n = arr.size();
        int left = low, right = mid + 1;
        while(left <= mid && right <= high){
            if(arr[left].first <= arr[right].first){
                result[arr[left].second] += (right - (mid + 1));
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            result[arr[left].second] += (right - (mid + 1));
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low;i<=high;i++){
            arr[i] = temp[i - low];
        }
    }
    void mergeSort(vector<pair<int, int>>& arr, int low, int high){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        result.resize(n, 0);
        vector<pair<int, int>> indexed(n);
        for(int i=0;i<n;i++)
            indexed[i] = {nums[i], i};
        mergeSort(indexed, 0, n -1);
        return result;
    }
};