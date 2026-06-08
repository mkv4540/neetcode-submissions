class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int>dp(obstacleGrid[0].size(), 0);
        dp[0] = obstacleGrid[0][0] ? 0 : 1;
        for (int row = 0; row < obstacleGrid.size(); row++){
            for (int col = 0; col < obstacleGrid[row].size(); col++){
                if (obstacleGrid[row][col] == 1){
                    dp[col] = 0;
                }else if (col > 0){
                    dp[col] += dp[col-1];
                }
            }
        }
        return dp[obstacleGrid[0].size()-1];
    }
};