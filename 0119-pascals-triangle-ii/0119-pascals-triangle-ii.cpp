class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pT(rowIndex + 1);
        long long ans = 1;
        pT[0] = 1;
        for(int i = 1;i<=rowIndex;i++){
            ans *= (rowIndex - i + 1);
            ans /= i;
            pT[i] = (int) ans;
        }
        //pT[rowIndex] = 1;
        return pT;
    }
};