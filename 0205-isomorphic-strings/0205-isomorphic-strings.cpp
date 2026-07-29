class Solution {
public:
    //This is the optimal solution with time complexity O(n) and space complexity O(1)
    bool isIsomorphic(string s, string t) {
        int ST[256];
        int TS[256];
        fill(ST, ST+256, -1);
        fill(TS, TS+256, -1);
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2) return false;
        for(int i = 0;i<n1;i++){
            if(ST[s[i]] == -1 && TS[t[i]] == -1){
                ST[s[i]] = t[i];
                TS[t[i]] = s[i];
            }
            else{
                if(ST[s[i]] != t[i] || TS[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};