class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for (int asteroid : asteroids){
            if (st.empty()){
                st.push(asteroid);
            }else{
               int destroyed = 0;
               while (st.size() && st.top() > 0 &&  asteroid < 0){
                    if (abs(st.top()) == abs(asteroid)){
                        st.pop();
                        destroyed = 1;
                        break;
                    }else{
                        asteroid = abs(st.top()) > abs(asteroid) ? st.top() : asteroid;
                        st.pop();
                    }
               } 
               if (!destroyed)
                st.push(asteroid);
            }
        }
        vector<int>ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};