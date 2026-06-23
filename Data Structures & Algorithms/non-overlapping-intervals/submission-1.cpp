class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        for (int index = 1; index < intervals.size(); index++){
            if (intervals[index-1][1] > intervals[index][0]){
                count++;
                intervals[index][1] = min(intervals[index-1][1], intervals[index][1]);
            }
        }
        return count;
    }
};
