class Solution {
public:
    void visit(vector<vector<int>>& grid, int row, int col, int &count, int &largest_size){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 2 || grid[row][col] == 0){
            return;
        }
        if (grid[row][col] == 1){
            count++;
            largest_size = max(largest_size, count);
            grid[row][col] = 2;
        }
        visit(grid, row + 1, col, count, largest_size);
        visit(grid, row, col + 1, count, largest_size);
        visit(grid, row - 1, col, count, largest_size);
        visit(grid, row, col-1, count, largest_size);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int largest_size = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col] == 1){
                    int count = 0;
                    visit (grid, row, col, count, largest_size);
                }
            }
        }
        return largest_size;
    }
};
