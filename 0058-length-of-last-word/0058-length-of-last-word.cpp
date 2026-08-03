class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        string word = "";
        int count = 0;
        while(i >= 0 && s[i] != ' '){
            word += s[i];
            i--; count++;
        }
        return word.length();
    }
};