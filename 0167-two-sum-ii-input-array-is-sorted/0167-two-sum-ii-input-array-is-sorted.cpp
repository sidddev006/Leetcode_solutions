class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans(2);
        for(int i = 0;i<n;i++){
            int rem = target - numbers[i];
            int low = i+1, high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(numbers[mid] == rem){
                    ans = {i+1, mid+1};
                    return ans;
                }
                else if(rem > numbers[mid]) low = mid +1;
                else high = mid - 1;
            }
        }
        return ans;
    }
};