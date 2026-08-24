class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size();i++){
            sum +=  nums[i];
            int rem = sum % k;
            if(remainderIndex.count(rem)){
                if(i - remainderIndex[rem] >= 2) return true;
            }
            else{
                remainderIndex[rem] = i;
            }
        }
        return false;
    }
};