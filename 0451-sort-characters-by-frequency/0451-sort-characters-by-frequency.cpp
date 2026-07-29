class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v;
        int freq[256];
        fill(freq, freq+256, 0);
        for(int i = 0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(int i = 0;i<256;i++){
            if(freq[i] > 0){
                v.push_back({freq[i], (char)i});
            }
        }
        sort(v.begin(), v.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        //reverse(v.begin(), v.end());
        string ans = "";
        for(const auto &p:v){
            ans.append(p.first, p.second);
        }
        return ans;
    }
};