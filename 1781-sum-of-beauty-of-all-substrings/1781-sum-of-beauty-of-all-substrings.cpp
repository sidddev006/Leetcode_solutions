class Solution {
public:
    int getBeauty(int freq[]){
        int maxfreq = INT_MIN;
        int minfreq = INT_MAX;
        for(int i = 0;i<26;i++){
            maxfreq = max(maxfreq, freq[i]);
            if(freq[i] != 0) minfreq = min(minfreq, freq[i]);
        }
        return maxfreq - minfreq;
    }
    int beautySum(string s) {
        int n = s.length();
        int beauty = 0;
        for(int i = 0;i<n;i++){
            int freq[26] = {0};
            for(int j = i;j<n;j++){
                freq[s[j] - 'a']++;
                beauty += getBeauty(freq);
            }
        }
        return beauty;
    }
};