class Solution {
public:
    void find_subsets(vector<int>&nums, int curr_index, vector<int>&curr, vector<vector<int>>&final_sets){
        final_sets.push_back(curr);
        for (int index = curr_index; index < nums.size(); index++){
            if (index > curr_index && nums[index] == nums[index-1]){
                continue;
            }
            curr.push_back(nums[index]);
            find_subsets(nums, index+1, curr, final_sets);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>final_sets;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        find_subsets(nums, 0, curr, final_sets);
        return vector<vector<int>>(final_sets.begin(), final_sets.end());
    }
};
