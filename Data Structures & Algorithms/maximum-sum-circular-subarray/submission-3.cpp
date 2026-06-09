class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, max_sum = INT_MIN, min_sum = INT_MAX, curr = 0, curr_min = 0, curr_max = 0;
        for (int index = 0; index < nums.size(); index++){
            curr_min = min(curr_min + nums[index], nums[index]);
            curr_max = max(curr_max + nums[index], nums[index]);
            max_sum = max(curr_max, max_sum);
            min_sum = min(curr_min, min_sum);
            sum += nums[index];
        }
        if (sum == min_sum){
            return max_sum;
        }
        return max(max_sum, sum - min_sum);
    }
};