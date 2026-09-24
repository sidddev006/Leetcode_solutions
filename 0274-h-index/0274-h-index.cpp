class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans = 0;
        for(int h = 1; h<=n;h++){
            if(citations[n-h] >= h) ans = max(ans, h);
        }
        return ans;
    }
};