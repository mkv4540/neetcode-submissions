class Solution {
public:
    
    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        return dp[n];
    }
};

// 1 2 3 4 5 6 7 8 9 10 11 12 13  
// 1 2 3 1 2 3 4 2 1  2  3  3  2  