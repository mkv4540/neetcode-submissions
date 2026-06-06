class Solution {
public:
    bool isValid(vector<int> &piles, int midRate, int hours){
        int curr_hours = 0;
        for (int pile : piles){
            curr_hours += ceil((double)pile/midRate);
            cout<<curr_hours<<midRate<<endl;
        }
        return curr_hours <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = 1;
        for (int pile : piles){
            maxRate = max(pile, maxRate);
        }
        int minRate = 1, ans = maxRate;

        while (minRate<=maxRate){
            int midRate = minRate + (maxRate - minRate)/2;
            if (isValid(piles, midRate, h)){
                maxRate = midRate - 1;
                ans = min (midRate, ans);
            }else{
                minRate = midRate + 1;
            }
        }
        return ans;
    }
};
