class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int index = 0; index < s.size(); index++){
            int left = index-1, right = index+1;
            count++;
            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    count++;
                    left--;
                    right++;
                }else{
                    break;
                }
            }
            left = index; right = index + 1;
            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    count++;
                    left--;
                    right++;
                }else{
                    break;
                }
            }
        }    
        return  count;   
    }
};
