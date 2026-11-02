class Solution {
public:
    int signFunc(int x){
        if(x > 0) return 1;
        else if(x = 0) return 0;
        else return -1;
    }
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(auto num: nums){
            if(num == 0) return 0;
            else if(num > 0) product *= 1;
            else product *= -1;
        }
        return signFunc(product);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna