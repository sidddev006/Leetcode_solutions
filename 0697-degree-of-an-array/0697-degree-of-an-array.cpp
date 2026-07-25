class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        map<int, int> firstIndex;
        map<int, int> lastIndex;
        int maxfreq = INT_MIN;
        int slen = INT_MAX;
        for(int i = 0; i<n;i++){
            if(freq[nums[i]] == 0){
                firstIndex[nums[i]] = i;
            } 
            lastIndex[nums[i]] = i;
            freq[nums[i]]++;
            maxfreq = max(maxfreq, freq[nums[i]]);
        }
        for(auto it: freq){
            if(it.second == maxfreq){
                int d = lastIndex[it.first] - firstIndex[it.first] + 1;
                slen = min(slen, d);
            }
        }
        return slen;

    }
};