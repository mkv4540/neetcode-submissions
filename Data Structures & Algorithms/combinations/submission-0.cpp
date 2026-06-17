class Solution {
public:
    void make_combinations(int n, int k, int curr_index, vector<int>&curr, vector<vector<int>>&ans){
        if (curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for (int index = curr_index; index <= n; index++){
            curr.push_back(index);
            make_combinations(n, k, index + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        make_combinations(n, k, 1, curr, ans);
        return ans;
    }
};