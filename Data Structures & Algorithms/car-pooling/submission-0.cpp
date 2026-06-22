class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>>track;
        for(vector<int>trip : trips){
            track.push_back({trip[1], trip[0]});
            track.push_back({trip[2], -trip[0]});
        }
        sort(track.begin(), track.end());
        for (int index = 0; index < track.size(); index++){
            capacity -= track[index][1];
            if (capacity < 0){
                return false;
            }
        }
        return true;
    }
};