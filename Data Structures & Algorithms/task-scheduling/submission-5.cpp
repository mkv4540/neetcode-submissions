class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mp;
        int max_freq = 0, max_freq_count = 0;
        for (char task : tasks){
            mp[task]++;
            if (max_freq < mp[task]){
                max_freq = mp[task];
                max_freq_count = 1;
            } else if (max_freq == mp[task]){
                max_freq_count++;
            }
        }
        return max(((n + 1) * (max_freq - 1) + max_freq_count), (int)tasks.size()); 
    }
};
// x . . x . . x 
// 2 +1 * 2)