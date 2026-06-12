class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& rotten_grid, int minute, int &ans){
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0){
            return;
        }
        if (rotten_grid[row][col] > minute){
            rotten_grid[row][col] = minute;
        }else{
            return;
        }
        dfs(grid, row + 1, col, rotten_grid, minute + 1, ans);
        dfs(grid, row, col+1, rotten_grid, minute + 1, ans);
        dfs(grid, row - 1, col, rotten_grid, minute + 1, ans);
        dfs(grid, row, col-1, rotten_grid, minute + 1, ans);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>>rotten_grid(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[row].size(); col++){
                if (grid[row][col] == 2){
                    dfs (grid, row, col, rotten_grid, 0, ans);
                }
            } 
        }
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[row].size(); col++){
                if (grid[row][col] == 1 && rotten_grid[row][col] == INT_MAX){
                    return -1;
                }
                cout<<rotten_grid[row][col]<<endl;
                if (rotten_grid[row][col] != INT_MAX)
                    ans = max(ans, rotten_grid[row][col]);
            }
        }
        return ans;

    }
};
