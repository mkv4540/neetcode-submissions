class MinStack {
public:
    stack<int>st;
    stack<int>min_st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        int curr_min = min_st.size()  == 0 ? val : min(val, min_st.top());
        min_st.push(curr_min);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
