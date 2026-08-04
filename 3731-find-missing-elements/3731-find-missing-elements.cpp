class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        vector<int> ans;
        for(int i = mini+1; i<maxi;i++){
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};