class Solution {
public:
    int calculate(int first, int second, string c){
        char d = c[0];
        switch(d){
            case '+':
                return first + second;
            case '*':
                return first * second;
            case '-':
                return second - first;
            case '/':
                return second / first;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        set<char>operator_set;
        int ans = 0;
        for (string c : tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int res = calculate(first, second, c);
                st.push(res);
            }else {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
