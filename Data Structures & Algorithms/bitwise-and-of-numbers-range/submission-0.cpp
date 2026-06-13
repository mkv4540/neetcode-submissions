class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        for (int index = left+1; index <= right; index++){
            ans = ans & index;
        }
        return ans;
    }
};