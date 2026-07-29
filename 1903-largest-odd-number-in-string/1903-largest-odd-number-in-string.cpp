class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int index = -1;
        string ans = "";
        for(int i = 0;i<n;i++){
            if((num[i]-'0') %2 == 1) index = i;
        }
        if(index == -1) return "";
        ans = num.substr(0, index + 1);
        return ans;
    }
};