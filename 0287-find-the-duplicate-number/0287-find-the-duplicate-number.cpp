class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //There is only one duplicate number
        int n = nums.size() + 1;
        unordered_set<int> st;
        for(int i = 1;i<n;i++){
            if(st.find(nums[i-1]) != st.end()) return nums[i-1];
            st.insert(nums[i-1]);
        }
        return -1;
    }
};