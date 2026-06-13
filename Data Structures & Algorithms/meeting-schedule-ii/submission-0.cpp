/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>>start_end;
        int meet_room_required = 0, curr_room = 0;
        for (Interval interval : intervals){
            start_end.push_back({interval.start, 1});
            start_end.push_back({interval.end, -1});
        }
        sort(start_end.begin(), start_end.end());
        for (pair<int, int>curr : start_end){
            curr_room += curr.second;
            meet_room_required = max(meet_room_required, curr_room);
        }
        return meet_room_required;
    }
};
