class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0, start = 0;
        for (int index = 0; index < s.size(); index++){
            int left = index-1, right = index+1, curr = 1;
            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    left--; right++;
                    curr+=2;
                }else{
                    break;
                }
            }
            if (curr > ans){
                ans = curr;
                start = left+1;
            }
            left = index; right = index+1; curr = 0;
            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    left--; right++;
                    curr+=2;
                }else{
                    break;
                }
            }
            cout<<curr<<endl;
            if (curr > ans){
                ans = curr;
                start = left+1;
            }
        }

        return s.substr(start, ans);
    }
};
