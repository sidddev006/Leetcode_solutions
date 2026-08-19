class Solution {
public:
    /*
    Dry run of test case:-
        s = "ADOBECODEBANC", t = "ABC"
        Return the minimum window substring of s such that every character in t is included in the window.
        Window 1:- "ADOBECODEBANC" 
    */
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> need, window;
        for(char c:t) need[c]++;
        int required = need.size();
        int formed = 0;
        int left = 0, minLen = INT_MAX, minStart = 0;
        for(int right = 0; right < m; right++){
            char c = s[right];
            window[c]++;
            if(need.count(c) && window[c] == need[c]) formed++;
            while(formed == required){
                if(right -left+1 < minLen){
                    minLen = right - left+1;
                    minStart = left;
                }
                char lc = s[left];
                window[lc]--;
                if(need.count(lc) && window[lc] < need[lc]) formed--;
                left++;
            }
        }
        return minLen == INT_MAX ?"": s.substr(minStart, minLen);
    }
};