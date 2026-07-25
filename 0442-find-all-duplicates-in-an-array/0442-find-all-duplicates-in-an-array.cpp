class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        unordered_map<int, int>mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > 1){
                st.insert(nums[i]);
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};