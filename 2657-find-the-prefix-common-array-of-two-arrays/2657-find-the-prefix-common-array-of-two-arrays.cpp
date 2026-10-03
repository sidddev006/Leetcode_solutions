class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>C(n);
        vector<int>freq(n+1, 0);
        int count = 0;
        for(int i = 0; i<n;i++){
            if(++freq[A[i]] == 2) count++;
            if(++freq[B[i]] == 2) count++;
            C[i] = count;
        }
        return C;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna