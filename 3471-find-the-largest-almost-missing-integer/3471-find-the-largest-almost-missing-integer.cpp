class Solution {
public:
//almost missing if it appears once in all the subarrays
    /*
    Dry run of test case:-
        [3,9,2,1,7], n-> 5 ;k = 3; number of subarrays - n-k+1
        the subarrays -> [3,9,2], [9,2,1], [2,1,7]
        the almost missing -> 3 and 7 in which 7 is the largest so 7 is the answer
        [3,9,7,2,1,7], n-> 6 ,k = 4
        the subarrays -> [3,9,7,2], [9,7,2,1], [7,2,1,7]
        the almost missing -> 3 which is also the answer as it is the only almost missing
        [0, 0], n = 2, k=1
        the subarrays -> [0], [0]
        the almost missing -> none so answer is -1
        [7,9,8,5,3,2,8], n = 7, k = 5
        the subarrays -> [7,9,8,5,3], [9,8,5,3,2], [8,5,3,2,8]
    */
    /* This is my first attempt it takes O(n.k) time complexity*/
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int n_sub = n-k+1;
        unordered_map<int, int> windowCount;
        int left = 0;
        for(int i = 0;i<n_sub;i++){
            unordered_set<int> distinctInWindow;
            for(int right = left; right < left + k;right++){
                distinctInWindow.insert(nums[right]);
            }
            for(int val: distinctInWindow){
                windowCount[val]++;
            }
            left++;
        }
        int maxi = -1;
        for(auto &it:windowCount){
            if(it.second == 1){
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
    //*/
    
};