class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};
