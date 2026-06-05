class NumMatrix {
public:
    vector<vector<int>>sumMatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        sumMatrix = matrix;
        for (int row = 0; row < matrix.size(); row++){
            for (int col = 0; col < matrix[row].size(); col++){
                sumMatrix[row][col] = sumMatrix[row][col] + (row > 0 ? sumMatrix[row-1][col]: 0) + (col > 0 ? sumMatrix[row][col-1]: 0) - ((row > 0 && col > 0) ? sumMatrix[row-1][col-1] : 0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2][col2] - (row1 > 0 ? sumMatrix[row1-1][col2]:0) - (col1 > 0 ? sumMatrix[row2][col1-1]:0) + ((row1 > 0 && col1 > 0 )? sumMatrix[row1-1][col1-1] :0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */