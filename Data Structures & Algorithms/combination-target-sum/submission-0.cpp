class Solution {
public:
    void calculate(vector<int>&nums, int sum, int target, int curr_index, vector<vector<int>>&ans, vector<int>&curr_set){
        if (sum >= target){
            if (sum == target)
                ans.push_back(curr_set);
            return;
        }
        for (int index = curr_index; index < nums.size(); index++){
            curr_set.push_back(nums[index]);
            calculate(nums, sum + nums[index], target, index, ans, curr_set);
            curr_set.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr_set;
        sort(nums.begin(), nums.end());
        calculate(nums, 0, target, 0, ans, curr_set);
        return ans;
    }
};
