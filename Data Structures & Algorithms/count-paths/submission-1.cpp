class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>path(n, 1);

        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                path[col] = path[col] + path[col-1];
            }
        }
        return path[n-1];
    }
};
