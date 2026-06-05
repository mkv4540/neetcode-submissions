class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        for (int index = 0; index < nums.size(); index++){
            int left = index + 1, right = nums.size() - 1;
            while (left < right){
                int curr_sum = nums[index] + nums[left] + nums[right];
                if (curr_sum == 0){
                    ans.insert({nums[index], nums[left], nums[right]});
                }
                if (curr_sum > 0) {
                    right--;
                }else{
                    left++;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
