class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // Empty t is a subsequence of any prefix of s exactly once
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j]; // skip s[i-1], don't use it to match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1]; // use s[i-1] to match t[j-1]
                }
            }
        }
        return (int)dp[n][m];
    }
};