class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        int open = 0, close = 0;
        for(int i  =0; i<n;i++){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) ans = max(ans, 2*close);
            else if(close>open) close=open = 0;
        }
        open = close = 0;
        for(int i  = n-1; i>=0; i--){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) ans = max(ans, 2*open);
            else if(close < open) close = open=0;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna