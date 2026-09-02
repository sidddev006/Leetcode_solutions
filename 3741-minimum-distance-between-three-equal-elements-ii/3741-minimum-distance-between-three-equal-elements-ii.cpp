class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>pos;
        for(int i = 0; i < (int)nums.size(); i++) pos[nums[i]].push_back(i);
        int ans = INT_MAX;
        for(auto &[val, idxs] : pos){
            for(int i = 0; i+2 < (int)idxs.size(); i++){
                ans = min(ans, 2* (idxs[i+2] - idxs[i]));
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};