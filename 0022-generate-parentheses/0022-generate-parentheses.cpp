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
        generate(n, "", 0, 0);
        return answers;
    }
};