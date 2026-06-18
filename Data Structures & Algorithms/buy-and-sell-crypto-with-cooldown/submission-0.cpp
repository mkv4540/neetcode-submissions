class Solution {
public:
    map<string, int>mp;
    int dp(vector<int>&prices, int index, bool canBuy){
        if (index >= prices.size()){
            return 0;
        }
        string key = to_string(index) + '.' + to_string(canBuy);
        if (mp[key]){
            return mp[key];
        }
        if (canBuy){
            int buy = - prices[index] + dp(prices, index+1, false);
            int skip = dp(prices, index+1, true);
            return mp[key] = max(buy, skip);
        }else{
            int sell = + prices[index] + dp(prices, index+2, true);
            int skip = dp(prices, index+1, false);
            return mp[key] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        return dp(prices, 0, true);
    }
};
