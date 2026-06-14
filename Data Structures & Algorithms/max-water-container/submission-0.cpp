class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0, right = heights.size() - 1, ans = 0;
        while (left < right){
            int curr_capacity = min(heights[left], heights[right]) * (right - left);
            ans = max (curr_capacity, ans);
            if (heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;

        
    }
};// 1 + 

// 1 + 7 + 2+ 5 + 4 + 6 + 6
