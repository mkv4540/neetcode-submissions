class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int ans = 0;
        for (int price : prices){
            if (price > low){
                ans += price - low;
                low = price;
            }else{
                low = price;
            }
        }
        return ans;
    }
};