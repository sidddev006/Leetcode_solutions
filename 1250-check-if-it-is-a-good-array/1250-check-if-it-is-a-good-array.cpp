class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        //This is Bézout's identity: for any two integers a, b, the smallest positive value achievable by a*x + b*y (over all integers x, y) is exactly gcd(a, b). So a*x + b*y = 1 has an integer solution if and only if gcd(a, b) = 1.
        int gcd1 = nums[0];
        if(gcd1 == 1) return true;
        int n = nums.size();
        for(int i = 1; i<n;i++){
            gcd1 = gcd(gcd1, nums[i]);
            if(gcd1 == 1) return true;
        }
        return false;
    }
};