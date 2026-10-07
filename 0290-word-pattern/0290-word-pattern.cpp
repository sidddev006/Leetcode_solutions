class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string w;
        while(ss>>w) words.push_back(w);
        unordered_map<char, string> mpp;
        unordered_map<string, char>smpp;
        if(words.size() != pattern.length()) return false;
        for(int i = 0; i<words.size(); i++){
            if(mpp.find(pattern[i]) == mpp.end()){
                if(smpp.find(words[i]) != smpp.end()) return false;
                smpp[words[i]] = pattern[i];
                mpp[pattern[i]] = words[i];
            }
            else{
                if(mpp[pattern[i]] != words[i]) return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna