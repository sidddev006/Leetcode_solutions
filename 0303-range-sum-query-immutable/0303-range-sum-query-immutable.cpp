class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        //build prefix
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+= nums[i];
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        //use prefix
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */