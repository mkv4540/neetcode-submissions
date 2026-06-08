class Solution {
public:
    int calculate(vector<int>&nums, int start, int end){
      vector<int>dp(nums.size(), 0);
      dp[start] = nums[start];
      if (end - start < 1){
        return nums[start];
      }
      dp[start+1] = max(nums[start], nums[start+1]);
      for (int index = start+2; index <= end; index++){
        dp[index] = max(nums[index] + dp[index-2], dp[index-1]);
      }
      return dp[end];
    }
    int rob(vector<int>& nums) {
      if (nums.size() == 1){
        return nums[0];
      }
      return max (calculate(nums, 0, nums.size()-2), calculate(nums, 1, nums.size()-1));
    }
};
