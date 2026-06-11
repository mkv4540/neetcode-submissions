class Solution {
public:
    void find_target_sum(vector<int> &candidates, int sum, int curr_index, vector<int>&curr, set<vector<int>>&sum_array, int target){
        if (sum > target){
            return;
        }
        if (sum == target){
            sum_array.insert(curr);
            return;
        }
        for (int index = curr_index; index < candidates.size(); index++){
            if (index > curr_index && candidates[index-1] == candidates[index]){
                continue;
            }
            curr.push_back(candidates[index]);
            find_target_sum(candidates, sum + candidates[index], index + 1, curr, sum_array, target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>>sum_array;
        vector<int>curr;
        find_target_sum(candidates, 0, 0, curr, sum_array, target);
        return vector<vector<int>>(sum_array.begin(), sum_array.end());
    }
};
