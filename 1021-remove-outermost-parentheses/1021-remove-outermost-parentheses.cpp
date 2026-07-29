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