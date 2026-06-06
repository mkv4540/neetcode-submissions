class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }
        int col_size =  matrix[0].size();
        int left = 0, right = matrix.size() * matrix[0].size() - 1; 
        while (left <= right){
            int mid = left + (right - left)/2;
            int row = (mid)/col_size, col = (mid) % col_size;
            // cout<<row<<col<<endl;
            if (matrix[row][col] == target){
                return true;
            }
            if (matrix[row][col] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
