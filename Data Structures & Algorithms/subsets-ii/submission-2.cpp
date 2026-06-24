class Solution {
public:
    void find_subsets(vector<int>&nums, int curr_index, vector<int>&curr, set<vector<int>>&final_sets){
        if (curr_index >= nums.size()){
            final_sets.insert(curr);
            return;
        }
        
        curr.push_back(nums[curr_index]);
        find_subsets(nums, curr_index+1, curr, final_sets);
        curr.pop_back();
        find_subsets(nums, curr_index+1, curr, final_sets);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>final_sets;
        sort(nums.begin(), nums.end());
        vector<int>curr;
        find_subsets(nums, 0, curr, final_sets);
        return vector<vector<int>>(final_sets.begin(), final_sets.end());
    }
};
