class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, cand1, cand2;
        for (int num : nums){
            if (cand1 == num){
                count1++;
            }else if (cand2 == num){
                count2++;
            }else if (count1 == 0) {
                cand1 = num;
                count1++;
            }else if (count2 == 0){
                cand2 = num;
                count2++;
            }else {
                count1--;
                count2--;
            }
        }
        int limit = nums.size()/3;
        vector<int>ans;
        count1 = count2 = 0;
        for (int num : nums){
            if (num == cand1){
                count1++;
            }
            if (num == cand2){
                count2++;
            }
        }
        if (count1 > limit){
            ans.push_back(cand1);
        }
        if (count2 > limit){
            ans.push_back(cand2);
        }
        return ans;
    }
};