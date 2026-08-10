class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        dp[0] = false;
        for(int j = 1; j<=n;j++){
            for(int i = 1;i*i<=j;i++){
            if(dp[j- i*i] == false) {
                dp[j] = true;
                break;
            }
            else dp[j] = false;
        }
        }
        return dp[n];
    }
};