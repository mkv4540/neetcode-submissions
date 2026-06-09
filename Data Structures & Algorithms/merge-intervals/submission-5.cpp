class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort (intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for (int index = 1; index < intervals.size(); index++){
            if (end >= intervals[index][0]){
                start = min(start, intervals[index][0]);
                end = max(end, intervals[index][1]);
            }else{
                res.push_back({start, end});
                start = intervals[index][0];
                end = intervals[index][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};
