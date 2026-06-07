class Solution {
public:

    void back_track(vector<int>&nums, set<vector<int>>&result, vector<int>&curr, int curr_index){
        result.insert(curr);
        for (int index = curr_index; index < nums.size(); index++){
            curr.push_back(nums[index]);
            back_track(nums, result, curr, index + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>result;
        vector<int>curr;
        back_track(nums, result, curr, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
