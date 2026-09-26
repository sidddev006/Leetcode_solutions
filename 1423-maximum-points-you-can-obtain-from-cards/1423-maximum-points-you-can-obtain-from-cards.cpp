class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int sum1 = 0;
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int minWindowSum = total;
        if(k == n) return total;
        int length = n-k;
        for(int right = 0; right < n; right++){
            sum1 += cardPoints[right];
            if(right - left +1 == length){
                minWindowSum = min(minWindowSum, sum1);
                sum1 -= cardPoints[left];
                left++;
            }
        }
        return total - minWindowSum;
    }
};