class Solution {
public:
    int count = 0;
    bool isSafe(vector<int>& cols, int row, int col){
        for(int r = 0; r < row; r++){
            if(cols[r] == col) return false;                          // same column
            if(abs(cols[r] - col) == abs(r - row)) return false;      // same diagonal
        }
        return true;
    }

    void solve(int row, int n, vector<int>& cols){
        if(row == n){
            count++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(cols, row, col)){
                cols.push_back(col);
                solve(row+1, n, cols);
                cols.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> cols;   // cols[r] = column of the queen placed in row r
        solve(0, n, cols);
        return count;
    }
};