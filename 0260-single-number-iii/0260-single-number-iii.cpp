class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        long long a = 0,  b = 0;
        for(auto num: nums) xorr ^= num;
        long long rightmost =  xorr & -xorr;
        for(auto num: nums){
            if(num & rightmost) a ^= num;
            else b ^= num;
        }
        return {(int)a, (int)b};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna