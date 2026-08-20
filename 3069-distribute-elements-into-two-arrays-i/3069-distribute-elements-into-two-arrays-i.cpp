class Solution {
public:
/*
thought process:-
I>  nums - [2,1,3] arr1->[2] arr2->[1]
    last element of arr2 -> 3 > last element of arr1->2, so arr1->[2], arr2->[3,1]
    now concatenate -> arr1+arr2 -> [2,3,1] -> answer
II> nums - [5,4,3,8], arr1 -> [5], arr2->[4]
    Ist iteration-> last element of arr2->4 < last element of arr1->5 , so arr1->[5,3], arr2->[4]
    IInd iteration -> last element of arr2->4 > last element of arr1->3, so arr1->[5,3], arr2->[4,8]
    now concatenate -> arr1+arr2-> [5,3,4,8] -> answer
*/
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2;i<n;i++){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};