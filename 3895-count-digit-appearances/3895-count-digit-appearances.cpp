class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int num: nums){
            int temp = num;
            while(temp != 0){
                int d = temp%10;
                if(d ==digit) count++;
                temp /= 10;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna