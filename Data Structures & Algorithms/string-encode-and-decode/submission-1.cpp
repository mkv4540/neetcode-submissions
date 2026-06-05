class Solution {
public:

    string encode(vector<string>& strs) {
           string ans = "";
           for (string str: strs){
             ans += to_string(str.size()) + '&' + str;
           }
           return ans;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string>ans;
        string curr_size = "";
        for (int index = 0; index < s.size(); index++){
            if(s[index] != '&'){
                curr_size += s[index];
            }else{
                ans.push_back(s.substr(index+1, stoi(curr_size)));
                index = index + stoi(curr_size);
                curr_size = "";
            }
        }
        return ans;
    }
};
