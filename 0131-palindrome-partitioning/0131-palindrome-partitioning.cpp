class Solution {
public:
    vector<vector<string>> answers;
    bool isPalin(string s){
        int n = s.size();
        int left = 0, right=n-1;
        while(left <= right){
            if(s[left]!=s[right]) return false;
            left++, right--;
        }
        return true;
    }
    void part(string s, int ind, string curr, int n, vector<string>path){
        if(ind == n){
            if(curr.empty()) answers.push_back(path);
            return;
        }
        string extended = curr + s[ind];
        if(isPalin(extended)){
            path.push_back(extended);
            part(s, ind+1, "", n, path);
            path.pop_back();
        }
        part(s, ind+1, extended, n, path);
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        string curr;
        vector<string>path;
        part(s, 0, "", n, path);
        return answers;
    }
};