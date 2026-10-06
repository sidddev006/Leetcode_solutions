class Solution {
  public:
  vector<int>answers;
  void solve(vector<int>& arr, int ind, int sum){
      if(ind == arr.size()) {
          answers.push_back(sum);
          return;
      }
      solve(arr, ind+1, sum+arr[ind]);
      solve(arr, ind+1, sum);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        solve(arr, 0, 0);
        return answers;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna