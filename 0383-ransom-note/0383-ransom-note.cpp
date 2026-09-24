class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rN[26] = {0};
        int m[26] = {0};
        for(char c : ransomNote) rN[c-'a']++;
        for (char c: magazine) m[c-'a']++;
        for(int i = 0; i<26; i++){
            if(rN[i] > m[i]) return false;
        }
        return true;
    }
};