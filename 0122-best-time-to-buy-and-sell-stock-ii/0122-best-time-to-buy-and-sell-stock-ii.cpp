class Solution {
public:
    int maxProfit(vector<int>& price) {
        int mini = price[0];
        int n = price.size();
        int profit = 0;
        for(int i = 1; i < n;i++){
            int cost = price[i];
            mini = min(mini,cost);
            if(cost - mini > 0) {
                profit += cost - mini;
                mini = price[i];
            }
        }
        return profit;
    }
};