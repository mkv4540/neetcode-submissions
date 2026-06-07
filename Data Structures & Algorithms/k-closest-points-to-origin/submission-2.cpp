class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>pq_closest;
        for (vector<int>point : points){
            int dis = point[0] * point[0] + point[1] * point[1];
            pq_closest.push({dis, {point[0], point[1]}});
            if (pq_closest.size() > k){
                pq_closest.pop();
            }
        }
        vector<vector<int>>ans;
        while (pq_closest.size()){
            ans.push_back({pq_closest.top().second.first, pq_closest.top().second.second});
            pq_closest.pop();
        }
        return ans;
    }
};
