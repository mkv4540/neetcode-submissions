class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;

        for (int index = 0; index < intervals.size(); index++){
            if (newInterval[0] > intervals[index][1]){
                result.push_back(intervals[index]);
            }else if (newInterval[1] < intervals[index][0]){
                result.push_back(newInterval);
                while (index < intervals.size()){
                    result.push_back(intervals[index]);
                    index++;
                }
                return result;
            }else{
                newInterval[0] = min(newInterval[0], intervals[index][0]);
                newInterval[1] = max(newInterval[1], intervals[index][1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
