class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int pos = 0, neg = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] < 0){
                int oldPos = pos;
                int oldNeg = neg;
                pos = (oldNeg == 0)? 0: oldNeg+1;
                neg = (oldPos == 0)?1: oldPos + 1;
            }
            if(nums[i] == 0){
                pos = 0;
                neg = 0;
            }
            if(nums[i] > 0){
                pos++;
                if(neg > 0) neg++;
            }
            ans = max(pos, ans);
            
        }
        return ans;
    }
};