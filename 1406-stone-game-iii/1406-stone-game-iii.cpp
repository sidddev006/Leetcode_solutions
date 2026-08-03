class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(4);
        for(int i = stoneValue.size() - 1;i>=0;--i){
            dp[i%4] = -1e9;
            for(int k = 0, take = 0;k<3&&i+k < stoneValue.size();++k)
                dp[i%4] = max(dp[i%4], (take += stoneValue[i+k]) - dp[(i+k+1) % 4]);
        }
        return dp[0] == 0? "Tie": (dp[0] > 0 ? "Alice": "Bob");
    }
};