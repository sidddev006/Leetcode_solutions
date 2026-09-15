class Solution {
public:
    vector<string> numbers;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void combinations(const string &digits, int ind, string curr, int n){
        if(ind == n){
            numbers.push_back(curr);
            return;
        }
        string letters = mapping[digits[ind] - '0'];
        for(char c: letters){
            combinations(digits, ind+1, curr+c, n);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        combinations(digits, 0, "", n);
        if(digits.empty()) return {};
        return numbers;
    }
};