class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occur;
        for(int num: arr) occur[num]++;
        unordered_set<int>val;
        for(auto it: occur){
            if(val.find(it.second) == val.end()){
                val.insert(it.second);
            }
            else return false;
        }
        return true;
    }
};