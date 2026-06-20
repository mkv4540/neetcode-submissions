class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int index = 0; index < nums.size(); index++){
            while (nums[index] != index+1){
                if (nums[index] == nums[nums[index]-1]){
                    return nums[index];
                }
                swap(nums[index], nums[nums[index]-1]);
            }
        }
        return -1;
    }
};
