class Solution {
public:
    bool isPossible(vector<int>&nums, int k){
        int n = nums.size();
        int prev_max = INT_MIN;
        for(int start = 0; start < n; start += k){
            int descents = 0;
            int mx = INT_MIN, mn = INT_MAX;
            for(int j = 0; j<k;j++){
                int cur = nums[start + j];
                int nxt = nums[start +(j+1)%k];
                if(cur > nxt) descents++;
                mn = min(mn, cur);
                mx = max(mx, cur); 
            }
            if(descents > 1) return false;
            if(mn < prev_max) return false;
            prev_max = mx;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 1; i<=n;i++){
            if(n%i == 0 && isPossible(nums, i)) sum += i;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna