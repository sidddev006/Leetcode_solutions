class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<string> beautiful;
        int cnt1 = 0;
        string temp = "";
        int left = 0;
        for(int right = 0; right < n;right++){
            if(s[right] == '1') cnt1++;
            while(cnt1 > k){
                if(s[left] == '1') cnt1--;   
                left++;
            }
            while(cnt1 == k && s[left] == '0'){             
                left++;
            }
            if(cnt1 == k) beautiful.push_back(s.substr(left, right - left+1));
        }
        string smallest = ""; int mini = INT_MAX;
        for(int i = 0; i< beautiful.size();i++){
            if((int)beautiful[i].length() < mini){
                mini = beautiful[i].length();
                smallest = beautiful[i];
            }
            else if((int)beautiful[i].length() == mini && beautiful[i]< smallest){
                smallest = beautiful[i];
            }
        }
        return smallest;
    }
};