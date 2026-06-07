class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        if (nums.size() == 1){
            return nums[0];
        }
        dp[1] = max(nums[0], nums[1]);
        for (int index = 2; index < nums.size(); index++){
            dp[index] = max(dp[index-1], dp[index-2] + nums[index]);
        }
        return dp.back();
    }
};
