class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int index = 1; index <= amount; index++){
            for (int coin : coins){
                if (index >= coin && dp[index - coin] != INT_MAX){
                    dp[index] = min(dp[index], 1 + dp[index-coin]);
                }
            }
        }
        return dp[amount] == INT_MAX?-1:dp[amount];
    }
};
