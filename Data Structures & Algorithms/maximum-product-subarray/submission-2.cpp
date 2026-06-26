class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_prod = nums[0], max_prod = nums[0], ans = nums[0];
        for (int index = 1; index < nums.size(); index++){
            if (nums[index] < 0){
                swap(max_prod, min_prod);
            }
            max_prod = max(nums[index], max_prod * nums[index]);
            min_prod = min(nums[index], min_prod * nums[index]);
            ans = max(max_prod, ans);
            ans = max(min_prod, ans);
        }
        return ans;
    }
};
