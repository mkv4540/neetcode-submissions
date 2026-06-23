class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       queue<int>q;
       q.push(0);
       vector<int>visited(s.size(), 0);
       visited[0] = 1;
       while(q.size()){
        int curr_pos = q.front();
        q.pop();
        for (int left = curr_pos+minJump; left <= min(curr_pos+maxJump, (int)s.size()-1); left++){
            if (visited[left] == 0 && s[left] == '0'){
                visited[left] = 1;
                q.push(left);
            }
        }
       } 
       return visited[s.size()-1];
    }
};