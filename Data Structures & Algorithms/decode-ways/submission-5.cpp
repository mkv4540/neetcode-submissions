class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1);
        if (s.size() == 0 || s[0] == '0'){
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        for (int index = 2; index <= s.size(); index++){
            if(s[index-1] != '0'){
                dp[index] += dp[index-1];
            }
            int curr = ((s[index-2] - '0') * 10) + ((s[index-1] - '0'));
            cout<<curr<<endl;
            if (curr >= 10 && curr <= 26){
                dp[index] += dp[index-2];
            }
        }
        return dp[s.size()];
    }
};
