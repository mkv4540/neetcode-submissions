class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for (int pos1 = 0; pos1 < nums.size(); pos1++){
            auto it = lower_bound(ans.begin(), ans.end(), nums[pos1]);
            if (it == ans.end()){
                ans.push_back(nums[pos1]);
            }else{
                *it = nums[pos1];
            }
        }
        return ans.size();
    }
};
