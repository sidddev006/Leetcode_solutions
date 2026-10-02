class Solution {
public:
    vector<string>answers;
    void generate(int n, string para,int open, int close){
        if(para.size() == 2*n){
            answers.push_back(para);
            return;
        }
        if(open < n){
            generate(n, para+'(', open+1, close);
        }
        if(close < open){
            generate(n, para + ')', open, close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        // Your implementation is correct! 
        // Approach: Backtracking. You are correctly maintaining the balance of parentheses.
        // Time Complexity: O(4^n / sqrt(n)) - This is the n-th Catalan number, which describes the number of valid parentheses sequences.
        // Space Complexity: O(n) - The depth of the recursion stack is 2n.
        // This is the optimal approach for this problem. You can safely submit this!
        generate(n, "", 0, 0);
        return answers;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna