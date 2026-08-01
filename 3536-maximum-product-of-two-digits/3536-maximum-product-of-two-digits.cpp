class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n != 0){
            int digit = n%10;
            ans.push_back(digit);
            n/=10;
        }
        sort(ans.begin(), ans.end());
        int s = ans.size();
        return ans[s-1] * ans[s-2];
    }
};