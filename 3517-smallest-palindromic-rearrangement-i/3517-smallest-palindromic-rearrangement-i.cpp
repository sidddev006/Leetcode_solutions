class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.length();i++){
            char c = s[i];
            freq[c - 'a']++;
        }
        string left = "", right = "", middle = "";
        for(int i =  0;i<26;i++){
            char ch = 'a' + i;
            if(freq[i]%2 == 1)
                middle+= ch;
            left+= string(freq[i]/2, ch);
        }
        right = left;
        reverse(right.begin(), right.end());
        return left+middle+right;
    }
};