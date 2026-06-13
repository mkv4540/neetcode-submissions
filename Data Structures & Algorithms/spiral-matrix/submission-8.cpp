class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return {};
        }
        vector<int>ans;
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        while (left <= right && top <= bottom){
            for (int index = left; index <= right; index++){
                ans.push_back(matrix[top][index]);
            }
            top++;
            for (int index = top; index <= bottom; index++){
                ans.push_back(matrix[index][right]);
            }
            right--;
            if (top <= bottom){
                for (int index = right; index >= left; index--){
                    ans.push_back(matrix[bottom][index]);
                }
                bottom--;
            }
            if (left <= right){
                for (int index = bottom; index >= top; index--){
                    ans.push_back(matrix[index][left]);
                }
                left++;
            }
        }
 
        return ans;
    }
};

