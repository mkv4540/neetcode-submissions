class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        vector<int>char_set(26, 0), target_set(26, 0);
        for (char c : s1){
            char_set[c-'a']++;
        }
        for (char c : s2){
            target_set[c-'a']++;
            while (target_set[c-'a'] > char_set[c-'a']){
                target_set[s2[left]-'a']--;
                left++;
            }
            if (char_set == target_set){
                return true;
            }
        }
        return false;
    }
};
