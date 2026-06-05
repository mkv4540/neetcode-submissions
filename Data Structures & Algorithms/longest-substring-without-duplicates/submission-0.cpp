class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>char_set;
        int left = 0, ans = 0;
        for (int index = 0; index < s.size(); index++){
            while (char_set.find(s[index]) != char_set.end()){
                char_set.erase(s[left++]);
            }
            ans = max(ans, index - left + 1);
            char_set.insert(s[index]);
        }
        return ans;
    }
};
