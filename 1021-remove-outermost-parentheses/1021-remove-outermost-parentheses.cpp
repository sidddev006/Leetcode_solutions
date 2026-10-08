class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balance = 0;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            if(s[i] == '('){
                if(balance > 0) ans+= '(';
                balance++;
            }
            else{
                balance--;
                if(balance > 0) ans+= ')';
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna