class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int pt1 = 1; pt1 <= text1.size(); pt1++)
            for (int pt2 = 1; pt2 <= text2.size(); pt2++){
                if (text1[pt1-1] == text2[pt2-1]){
                    dp[pt1][pt2] = 1 + dp[pt1-1][pt2-1];
                }else{
                    dp[pt1][pt2] = max(dp[pt1-1][pt2], dp[pt1][pt2-1]);
                }
            }
        return dp[text1.size()][text2.size()];
    }
};
