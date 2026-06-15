class Solution {
public:
    void dfs(vector<vector<int>>&grid, int row, int col, int dis){
        
        if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && (grid[row][col] > dis || dis == 0) && grid[row][col] != -1){
            grid[row][col] = dis;
        }else{
            return;
        }
        dfs(grid, row+1, col, dis+1);
        dfs(grid, row, col+1, dis+1);
        dfs(grid, row-1, col, dis+1);
        dfs(grid, row, col-1, dis+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
         for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[row].size(); col++){
                if (grid[row][col] == 0){
                    dfs(grid, row, col, 0);
                }
            }
         }
    }
};
