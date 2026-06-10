class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>st;
        vector<int>ans(temperatures.size(), 0);
        for (int index = 0; index < temperatures.size(); index++){
            while (st.size() && st.top().first < temperatures[index]){
                ans[st.top().second] = index - st.top().second;
                st.pop();
            }
            st.push({temperatures[index], index});
        }
        while (st.size()){

            ans[st.top().second] = 0;
            st.pop();
        }
        return ans; 
    }
};
