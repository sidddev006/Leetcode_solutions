class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minL = INT_MAX;
        for(int i =0;i<strs.size(); i++){
            minL = min(minL, (int)strs[i].length());
        }
        string cp = "";
        for(int i = 0;i<minL;i++){
            char c = strs[0][i];
            bool flag = true;
            for(int j = 0;j<strs.size();j++){
                char ci = strs[j][i];
                if(ci != c) {
                    flag = false;
                    break;
                }                
            }
            if(flag == true) cp += c;
            else return cp;
        }
        return cp;
    }
};