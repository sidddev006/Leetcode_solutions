class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>digit_sum;
        vector<pair<pair<int, int>, int>>v;
        //calculating digit sum
        for(int i = 0; i<n;i++){
            int x = nums[i], sum = 0;
            while(x!=0){
                sum += (x%10);
                x/=10;
            }
            v.push_back({{sum, nums[i]}, i});
        }
        sort(v.begin(), v.end());
        vector<bool>visited(n, false);
        int swaps = 0;
        for(int i = 0; i<n;i++){
            if(visited[i] || v[i].second == i) continue;
            int cycleLen = 0;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                j = v[j].second;
                cycleLen++;
            }
            swaps += cycleLen - 1; 
        }
        return swaps;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna