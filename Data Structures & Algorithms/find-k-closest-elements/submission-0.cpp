class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>>pq;
        vector<int>ans;
        int curr_pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int right = min((int)arr.size()-1, curr_pos+k);
        for (int index = max(0, curr_pos-k); index <= right; index++){
            pq.push({abs(x-arr[index]), arr[index]});
            if (pq.size() > k){
                pq.pop();
            }
        }
        while (pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};