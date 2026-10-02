class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        int left = 0;
        int cnt_odd = 0;
        int prefix = 0;
        for(int right = 0; right<n;right++){
            if(nums[right] % 2 != 0) {
                cnt_odd++;
                prefix = 0;
            }
            while(cnt_odd == k){
                prefix++;
                if(nums[left] % 2) cnt_odd--;
                left++;
            }
            count += prefix;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna