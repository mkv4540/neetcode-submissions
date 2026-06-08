class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        for (int pt1 = 0; pt1 < nums.size(); pt1++){
            for (int pt2 = pt1 + 1; pt2 < nums.size(); pt2++){
                int left = pt2 + 1, right = nums.size() - 1;
                while (left < right){
                    long long sum = (long long)nums[pt1] + nums[pt2] + nums[left] + nums[right];
                    if (sum == target){
                        ans.insert({nums[pt1], nums[pt2], nums[left], nums[right]});
                    }
                    if (sum > target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};