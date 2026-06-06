class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, ans = 0, maxFreq = 0;
        vector<int>char_arr(26, 0);
        for (int index = 0; index < s.size(); index++){
            char_arr[s[index] - 'A']++;
            maxFreq = max(maxFreq, char_arr[s[index] - 'A']);
            int window_size = index - left + 1;
            if (window_size - maxFreq > k){
                char_arr[s[left] - 'A']--;
                left++;
            }
            ans = max (ans, index - left + 1);
        }
        return ans;

    }
};
