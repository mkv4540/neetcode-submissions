class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1);
        dp[0] = 1;
        for (int index = 1; index <= target; index++){
            for (int num : nums){
                if (index >= num)
                    dp[index] += dp[index-num];
            }
        }
        return dp[target];
    }
};