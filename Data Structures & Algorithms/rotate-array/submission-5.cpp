class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k = k % nums.size();
       reverse (nums.end()-k, nums.end()); // a, b'
       reverse (nums.begin(), nums.end() - k); // a', b'
       reverse(nums.begin(), nums.end());
    }
};

// 1 2 3 4 5 6 7
// a b
// a' b
// 2 1 3 4 5 6 7
// 2 1 7 6 5 4 3
// 3 4 5 6 7 1 2
// a' b'
// b a
// 
// 
// 3 4 5 6 7 1 2
//
// 1 2 3 4 5 7 6
// 5 4 3 2 1 7 6
// 6 7 1 2 3 4 5
// 6 7 1 2 3 4 5