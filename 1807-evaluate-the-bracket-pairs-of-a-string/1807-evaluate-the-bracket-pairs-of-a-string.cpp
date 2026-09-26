class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n_key = knowledge.size();
        unordered_map<string, string> key_value;
        for(int i = 0; i<n_key; i++){
            key_value[knowledge[i][0]] = knowledge[i][1];
        }
        int n_s = s.size();
        string resulting = ""; 
        bool bracket_open = false;
        string key = "";
        for(int i = 0; i<n_s;i++){
            if(s[i] == '('){
                bracket_open = true;
            }
            else if(s[i] == ')'){
                resulting += key_value.find(key) != key_value.end() ? key_value[key] : "?";
                bracket_open = false;
                key = "";
            }
            else if(bracket_open == true){
                key+=s[i];
            }            
            else if (bracket_open == false){
                resulting += s[i];
            }
        } 
        return resulting;
    }
};