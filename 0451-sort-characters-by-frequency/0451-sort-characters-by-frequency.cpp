class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        int freq[256];
        fill(freq, freq+256, 0);
        for(int i = 0;i<n;i++){
            freq[s[i]]++;
        }
        int maxi = INT_MIN;
        for(int i = 0;i<256;i++){
            maxi = max(maxi, freq[i]);
        }
        string ans = "";
        for(int f = maxi;f>=0;f--){
            for(int k = 0;k<256;k++){
                if(freq[k] == f){
                    for(int i = 0 ;i < f;i++) ans+= (char)k;
                }
            }
        }
        return ans;
    }
};