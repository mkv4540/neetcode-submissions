class Solution {
public:
    int jump(vector<int>& nums) {
        int max_far = 0;
        int jump = 0;
        int farthest = 0;
        for (int index = 0; index < nums.size() - 1; index++){
            max_far = max(max_far, index + nums[index]);
            if (index == farthest){
                jump++;
                farthest = max_far;
            }
        }
        return jump;
    }
};
