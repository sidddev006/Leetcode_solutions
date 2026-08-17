class Solution {
public:
    vector<vector<int>> memo;
    vector<int> prefix;
    
    int rangeSum(int i, int j){
        return prefix[j+1] - prefix[i];
    }

    int solve(int i, int j){
        if(i == j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int best = 0;
        for(int k = i; k<j;k++){
            int leftSum = rangeSum(i, k);
            int rightSum = rangeSum(k+1, j);
            if(leftSum < rightSum){
                best = max(best, leftSum + solve(i, k));
            }
            else if(leftSum > rightSum){
                best = max(best, rightSum + solve(k+1, j));
            }
            else{
                best = max(best, leftSum + solve(i, k));
                best = max(best, rightSum + solve(k+1, j));
            }
        }
        return memo[i][j] = best;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.assign(n+1, 0);
        for(int i = 0; i<n;i++) prefix[i+1] = prefix[i] + stoneValue[i];
        memo.assign(n, vector<int>(n, -1));
        return solve(0, n-1);
    }
};