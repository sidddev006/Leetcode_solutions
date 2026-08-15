class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int n = nums.size();
        bool non_zero = false;

        for(int num:nums){
            total_xor^= num;
            if(num != 0){
                non_zero = true;
            }
        }
        //There can be three conditions, the xor is non-zero, the xor is zero but the elements are non_zero and the third condition xor is zero with the elements being zeros
        if(total_xor != 0) return n;
        if(total_xor == 0 && non_zero == true) return n-1;
        else return 0;
    }
};