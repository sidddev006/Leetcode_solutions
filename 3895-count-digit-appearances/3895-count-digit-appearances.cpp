class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        // Time Complexity: O(N * D) where N = nums.size() and D = number of digits per number (≤10).
        // Space Complexity: O(1) extra space.
        // NOTE: This implementation does NOT count occurrences of digit 0 in numbers that are exactly 0.
        // The while(temp != 0) loop is skipped for num == 0, so if digit == 0 you miss those occurrences.
        // Hint: Handle the zero case separately before the while loop.
        // Example fix (as a hint, not full rewrite):
        //   if (num == 0) {
        //       if (digit == 0) count++;
        //       continue; // skip further processing for this number
        //   }
        int count = 0;
        for(int num: nums){
            if(num == 0){
                if(digit == 0) count++;
                continue;
            }
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