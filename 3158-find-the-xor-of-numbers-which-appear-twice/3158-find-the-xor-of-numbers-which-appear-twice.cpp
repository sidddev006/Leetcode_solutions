class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        long long seen = 0;
        int result = 0;
        for(auto  num: nums){
            if((seen >>num) & 1) result ^= num;
            else seen |=  (1LL << num);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna