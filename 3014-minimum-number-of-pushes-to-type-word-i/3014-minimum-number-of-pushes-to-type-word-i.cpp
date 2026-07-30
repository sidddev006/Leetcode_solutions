class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int freq[26] = {0};
        int ans = 0;
        for(char c : word){
            freq[c-'a']++;
        }
        sort(freq, freq+26, greater<int>());
        for(int i = 0;i<26;i++){
            if(freq[i] == 0) break;
            int cost = (i/8 + 1);
            ans += freq[i] * cost;
        }
        return ans;
    }
};