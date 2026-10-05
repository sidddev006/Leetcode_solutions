class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int contentChildren = 0;
        int cookieIndex = 0;
        while(cookieIndex < s.size() && contentChildren < g.size()){
            if(s[cookieIndex] >= g[contentChildren]) contentChildren++;
            cookieIndex++;
        }
        return contentChildren;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna