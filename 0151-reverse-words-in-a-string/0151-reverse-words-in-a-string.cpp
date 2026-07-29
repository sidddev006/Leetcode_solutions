class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.length();
        while(i < n){
            //skipping all spaces
            while(i < n && s[i] == ' ')
                i++;
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            if(!word.empty())
                words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string ans = "";
        for(int i = 0;i<words.size();i++){
            if(i==0) ans+= words[i];
            else ans+= " "+words[i];
        }
        return ans;
    }
};