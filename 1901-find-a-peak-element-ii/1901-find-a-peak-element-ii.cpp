class Solution {
public:
    int findMI(vector<vector<int>>& nums, int n, int m, int col){
        int maxValue = -1;
        int index = -1;
        for(int i = 0;i<n;i++){
            if(nums[i][col] > maxValue){
                maxValue = nums[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low  = 0, high = m -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int mRI = findMI(mat, n, m, mid);
            int left = mid - 1>=0 ? mat[mRI][mid - 1]: -1;
            int right = mid+1 < m ? mat[mRI][mid+1] : -1;
            if(mat[mRI][mid] > left && mat[mRI][mid] > right){
                return {mRI, mid};
            }
            else if(mat[mRI][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};