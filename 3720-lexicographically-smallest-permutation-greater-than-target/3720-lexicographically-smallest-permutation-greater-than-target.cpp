class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(char c:s) freq[c-'a']++;
        vector<int> f = freq;
        int best_k = -1;
        for(int k = 0; k<n;k++){
            int tc = target[k] - 'a';
            for(int c  = tc+1; c < 26; c++){
                if(f[c] > 0){
                    best_k = k;
                    break;
                }
            }
            if(f[tc] == 0) break;
            f[tc]--;
        }
        if(best_k == -1) return "";
        vector<int> f2 = freq;
        for(int i = 0; i < best_k; i++) f2[target[i] - 'a']--;
        int chosen = -1;
        for(int c = target[best_k] - 'a'+1; c<26;c++){
            if(f2[c] > 0) {chosen = c;  break;}
        }
        f2[chosen]--;
        string ans = target.substr(0, best_k);
        ans += (char)('a'+chosen);
        for(int  c = 0; c<26; c++)
            ans += string(f2[c], (char)('a'+c));
        return ans;
    }
};