class Solution {
public:
    void dfs_fill (vector<vector<char>>& grid, int row, int col){
        if (row >= grid.size() || col >= grid[row].size() || row < 0 || col < 0 || grid[row][col] != '1'){
            return;
        }
        grid[row][col] = '2';
        dfs_fill (grid, row+1, col);
        dfs_fill (grid, row, col+1);
        dfs_fill (grid, row, col-1);
        dfs_fill (grid, row-1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[row].size(); col++){
                if (grid[row][col] == '1'){
                    dfs_fill (grid, row, col);
                    count++;
                }
            }
        }
        return count;
    }
};
