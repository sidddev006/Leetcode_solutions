class Solution {
public:
    int scoreOfString(string s) {
        int diff = 0, n = s.length();
        for(int i = 0; i<n-1; i++){
            diff += abs(s[i]-s[i+1]);
        }
        return diff;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna