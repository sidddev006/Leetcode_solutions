class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>answers(n+1);
        for(int i = 0; i<=n;i++){
            int count = 0;
            int j =i;
            while(j!=0){
                if(j & 1)count++;
                j>>=1;
            }
            answers[i] = count;
        }
        return answers;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna