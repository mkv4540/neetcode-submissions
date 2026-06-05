class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>prefix;
        int sum = 0, ans = 0;
        prefix[0] = 1;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
            ans += prefix[sum-k];
            prefix[sum]++;
            cout<<sum<<endl;
            
        }
        return ans;
    }
};