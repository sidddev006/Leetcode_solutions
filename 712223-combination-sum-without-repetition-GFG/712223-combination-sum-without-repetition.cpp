class Solution {
  public:
  vector<vector<int>>answers;
  void solve(vector<int>& arr, int target,int ind, vector<int>&curr){
      if(target == 0){
          answers.push_back(curr);
          return;
      }
      if(ind ==  arr.size()|| target < 0) return;
      curr.push_back(arr[ind]);
      solve(arr, target - arr[ind], ind+1, curr);
      curr.pop_back();
      while(ind+1 < arr.size() && arr[ind+1]==arr[ind]) ind++;
      solve(arr, target, ind+1, curr);
  }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int>curr;
        solve(arr, target, 0, curr);
        return answers;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna