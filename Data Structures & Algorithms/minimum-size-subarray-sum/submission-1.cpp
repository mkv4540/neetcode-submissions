class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, ans = INT_MAX;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
            while (left <= index && sum >= target){
                sum -= nums[left];
                ans = min(index-left+1, ans);
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};