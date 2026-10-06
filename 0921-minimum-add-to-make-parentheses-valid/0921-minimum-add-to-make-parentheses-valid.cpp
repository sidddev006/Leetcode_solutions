class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;
        int minAddsRequired = 0;
        for(char c: s){
            if(c=='(') openBrackets++;
            else{
                openBrackets>0?openBrackets-- : minAddsRequired++;
            }
        }
        return minAddsRequired + openBrackets;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna