class NumMatrix {
private: 
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        sums.assign(rows+1, vector<int>(cols+1));
        for(int row = 1; row<=rows;row++){
            int sum = 0;
            for(int col = 1; col <= cols; col ++){
                sums[row][col] = sums[ row-1][ col] + sums[ row][ col-1] - sums[ row-1][ col-1] + matrix[ row-1][ col-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obcol= new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */