class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, left = 0, ans = 0;
        vector<int>charArr(26, 0);
        for (int index = 0; index < s.size(); index++){
            charArr[s[index] - 'A']++;
            maxFreq = max(maxFreq, charArr[s[index] - 'A']);
            int window_size = index - left + 1;
            if (window_size - maxFreq > k){
                charArr[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, index - left + 1);
        }
        return ans;
    }
};
