class Solution {
public:
    // Brute force. time complexity is 0(n log n) and space complexity is O(n)
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp1;
        map<char, char> mpp2;
        if(s.length() != t.length()) return false;
        for(int i = 0;i<s.size();i++){
            if(mpp1.count(s[i]) == 0 && mpp2.count(t[i]) == 0){
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
            else{
                if(mpp1[s[i]] != t[i] || mpp2[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};