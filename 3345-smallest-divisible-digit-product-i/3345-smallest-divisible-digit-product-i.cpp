class Solution {
public:
    int digipro(int n){
        int temp = n;
        int pro = 1;
        while(temp != 0){
            pro *= temp%10;
            temp/=10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digipro(n) % t == 0) return n;
            else{
                n+= 1;
            }
        }
        return n;
    }
};