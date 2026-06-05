class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map_string;
        for (int index = 0; index < strs.size(); index++){
            string key = strs[index];
            sort(key.begin(), key.end());
            map_string[key].push_back(strs[index]);
        }
        vector<vector<string>>ans;
        for (auto itr : map_string){
            ans.push_back(itr.second);
        }
        return ans;
    }
};
