class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> y(n);
        vector<int> x(n);
        vector<int> ans(2*n);
        for(int i = 0; i<n;i++){
            x[i] = nums[i];
        }
        for(int j = n; j<2*n;j++){
            y[j-n] = nums[j];
        }
        int count = 0;
        for(int i = 0; i<2*n;i+=2){
            ans[i] = x[count];
            ans[i+1] = y[count];
            count++; 
        }
        return ans;
    }
};