class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>mp;
        if (nums.size() == 0){
            return 0;
        }
        int ans = 1;
        for (int num : nums){
            mp[num] = 1;
        }
        for (int num : nums){
            if (mp[num] == 0){
                continue;
            }
            int curr = num;
            int count = 1;
            mp[curr] = 0;
            while (mp[curr-1]){
                mp[curr-1] = 0;
                count++;
                curr--;
                
            }
            curr = num;
            while (mp[curr+1]){
                mp[curr+1] = 0;
                count++;
                curr++;
                
            }
            cout<<count<<endl;
            ans = max(ans, count);
        }
        return ans;
    }
};
