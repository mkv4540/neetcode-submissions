class Solution {
public:
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<int>>&heights, int row, int col, vector<vector<int>>&visited){

        visited[row][col] = 1;

        for (int d = 0; d < 4; d++){
            int next_row = row + dir[d][0];
            int next_col = col + dir[d][1];
            if (next_row < 0 || next_col < 0 || next_row >= heights.size() || next_col >= heights[0].size() || visited[next_row][next_col] || heights[row][col] > heights[next_row][next_col]){
                continue;
            }
            dfs(heights, next_row, next_col, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>atlantic(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>>pacific = atlantic;
        vector<vector<int>>ans;
        for (int col = 0; col < heights[0].size(); col++){
            dfs(heights, 0, col, pacific);
        }
        for (int row = 0; row < heights.size(); row++){
            dfs(heights, row, 0, pacific);
        }
        for (int col = 0; col < heights[0].size(); col++){
            dfs(heights, heights.size()-1, col, atlantic);
        }
        for (int row = 0; row < heights.size(); row++){
            dfs(heights, row, heights[0].size()-1, atlantic);
        }
        for (int row = 0; row < heights.size(); row++){
            for (int col = 0; col < heights[row].size(); col++){
                if (pacific[row][col] && atlantic[row][col]){
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
};
