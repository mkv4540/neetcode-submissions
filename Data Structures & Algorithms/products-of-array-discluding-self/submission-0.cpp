class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int>numsRight(nums.size(), 1), numsLeft(nums.size(), 1);
        numsLeft[0] = nums[0];
        numsRight[nums.size()-1] = nums[nums.size()-1];
        for (int index = 1; index < nums.size(); index++){
            numsLeft[index] = nums[index] * numsLeft[index-1]; 
        }
        for (int index = nums.size()-2; index >= 0; index--){
            numsRight[index] = numsRight[index+1] * nums[index]; 
        }
        vector<int>ans;
        ans.push_back(numsRight[1]);
        for (int index = 1; index < nums.size()-1; index++){
            ans.push_back(numsRight[index+1] * numsLeft[index-1]);
        }
        ans.push_back(numsLeft[nums.size()-2]);
        return ans;
    }
};
