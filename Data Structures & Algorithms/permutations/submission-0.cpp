class Solution {
public:
    vector<vector<int>>ans;
    void perm(vector<int>& nums, vector<int>&used, vector<int>&curr){
        if (curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for (int index = 0; index < nums.size(); index++){
            if (used[index] == 0){
                curr.push_back(nums[index]);
                used[index] = 1;
                perm(nums, used, curr);
                used[index] = 0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>used(nums.size());
        vector<int>curr;
        perm(nums, used, curr);
        return ans;
    }
};
