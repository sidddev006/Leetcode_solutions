class Solution {
public:
    int sq(int n){
        int square = 0;
        while(n > 0){
            square += (n % 10) *(n % 10);
            n/=10;
        }
        return square;
    }
    bool countseen(int n, unordered_set<int>& seen){
        if(n == 1) return true;
        if(seen.count(n)) return false;
        seen.insert(n);
        return countseen(sq(n), seen);
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        return countseen(n, seen);
    }
};