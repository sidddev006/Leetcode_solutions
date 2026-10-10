class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int len_pref = pref.size();
        for(auto w: words){
            if(w.substr(0,len_pref) == pref) count++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna