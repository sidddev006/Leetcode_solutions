class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> ans;
        for(int num : nums)
            mpp[num]++;
        vector<pair<int, int>> freq(mpp.begin(), mpp.end());
        sort(freq.begin(), freq.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });// This is used to sort the array in descending order
        for(int i = 0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};