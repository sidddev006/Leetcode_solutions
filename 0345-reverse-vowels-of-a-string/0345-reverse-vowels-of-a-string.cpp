class Solution {
public:
/*
    Dry run :-
    s = "IceCreAm"
    output = "AceCreIm"
    left = 0, right = n

*/
    bool isVowel(char ch){
        ch = tolower(ch);
        return string("aeiou").find(ch) != string::npos;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            if(isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left], s[right]);
                left++, right--;
            }
            else if(isVowel(s[left]) && !isVowel(s[right])) right--;
            else if (!isVowel(s[left]) && isVowel(s[right])) left++;
            else{
                left++, right--;
            }
        }
        return s;
    }
};