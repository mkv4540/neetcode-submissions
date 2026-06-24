class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, count_boat = 0;
        while (left <= right){

            if (people[left] + people[right] > limit){      
                right--;
            }else{
                left++;
                right--;
            }
            count_boat++;
        }
        // 123
        return count_boat;
    }
};