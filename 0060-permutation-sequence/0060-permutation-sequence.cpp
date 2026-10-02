class Solution {
public:
    string getPermutation(int n, int k) {
        // Time Complexity: O(n^2) because of the vector::erase operation inside the loop.
        // Space Complexity: O(n) to store the numbers and the result string.
        // This is the optimal approach for this problem given the constraints (n <= 9).
        
        int fact = 1;
        vector<int>numbers;
        for(int i  = 1; i<n;i++){
            numbers.push_back(i);
            fact *= i;
        }
        numbers.push_back(n);
        k = k- 1;//working with 0 index
        string ans = "";
        while(true){
            ans =  ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size() == 0) break;
            k = k%fact;
            fact = fact/numbers.size();
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna