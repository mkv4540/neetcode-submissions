class Solution {
public:
    bool is_valid(vector<int>&weights, int days, int curr_limit){
        int count = 0, sum = 0;
        for (int weight : weights){
            if (sum == 0){
                count++;
            }
            sum += weight;
            if (weight > curr_limit){
                return false;
            }
            if (sum > curr_limit){
                sum = weight;
                count++;
            }
        }
        return days >= count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int upper_limit = 0, lower_limit = 0, ans = INT_MAX;
        for (int weight : weights){
            upper_limit += weight;
            lower_limit = max(weight, lower_limit);
        }
        while (lower_limit <= upper_limit){
            int curr_limit = lower_limit + (upper_limit - lower_limit)/2;
            if (is_valid(weights, days, curr_limit)){
                ans = min(ans, curr_limit);
                upper_limit = curr_limit - 1;
            }else{
                lower_limit = curr_limit + 1;
            }
        }
        return ans;
    }
};