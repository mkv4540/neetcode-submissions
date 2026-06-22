class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int index = 0; index < nums.size(); index++){
            if (index > max_reach){
                return false;
            }
            max_reach = max(index + nums[index], max_reach);
        }
        return true;
    }
};
