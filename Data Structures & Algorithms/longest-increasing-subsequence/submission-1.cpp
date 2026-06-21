class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        int ans = 1;
        for (int pos1 = 0; pos1 < nums.size(); pos1++){
            for (int pos2 = pos1+1; pos2 < nums.size(); pos2++){
                if (nums[pos1] < nums[pos2]){
                    dp[pos2] = max(dp[pos2], dp[pos1] + 1); 
                    ans = max(dp[pos2], ans);
                }
            }
        }
        return ans;
    }
};
