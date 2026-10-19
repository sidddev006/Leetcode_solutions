class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i<32; i++){
            int sum = 0;
            for(int num: nums){
                if((num>> i) &1) sum++;
            }
            if(sum % 3 != 0) result =  result | (1<<i);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna