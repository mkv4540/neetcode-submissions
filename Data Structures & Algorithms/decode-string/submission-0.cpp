class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>>st;
        string curr = "";
        string curr_num = "";
        for (int index = 0; index < s.size(); index++){
            if (s[index] >= '0' && s[index] <= '9'){
                curr_num += s[index];
            }else if (s[index] == '['){
                st.push({curr, stoi(curr_num)});
                curr = "";
                curr_num = "";
            }else if (s[index] == ']'){
                auto [prev, repeat] = st.top();
                st.pop();
                string decode = prev;
                while(repeat--){
                     decode += curr;
                }
                curr = decode;
            }else{
                curr += s[index];
            }
        }
        return curr;

    }
};