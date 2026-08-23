class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int mid = n/2;
        int cnt1 = 0, cnt2 = 0;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i<mid; i++){
            if(num[i] == '?') cnt1++;
            else sum1+= num[i] - '0';
        }
        for(int i = mid; i<n; i++){
            if(num[i] == '?') cnt2++;
            else sum2+= num[i]-'0';
        }
        int totalIQ = cnt1+cnt2;
        int diff = sum1 - sum2;
        if(totalIQ %2 != 0) return true;
        return diff *2 != (cnt2 - cnt1) * 9;
    }
};