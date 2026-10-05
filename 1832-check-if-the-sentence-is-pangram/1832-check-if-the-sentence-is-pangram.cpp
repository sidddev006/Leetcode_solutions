class Solution {
public:
    bool checkIfPangram(string sentence) {
        int freq[26] = {0};
        for(char s: sentence) freq[s-'a']++;
        for(int f: freq) if(f==0) return false;
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna