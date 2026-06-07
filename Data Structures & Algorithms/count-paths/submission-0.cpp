class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>path(m, vector<int>(n, 1));

        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                path[row][col] = path[row-1][col] + path[row][col-1];
            }
        }
        return path[m-1][n-1];
    }
};
