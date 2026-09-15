class Solution {
public:
    vector<vector<int>> answers;
    void comb_calculate(int target, vector<int>& curr, int n, int ind){
        if(curr.size() == n){
            if(target == 0){
                answers.push_back(curr);
            }
            return;
        }
        if(ind > 9 || target < 0) return;
        curr.push_back(ind);
        comb_calculate(target-ind, curr, n, ind+1);
        int next = ind+1;
        curr.pop_back();
        comb_calculate(target, curr, n, ind+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        comb_calculate(n,curr, k, 1);
        return answers;
    }
};