class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>rows(9, vector<int>(10, 0));
        vector<vector<int>>cols(9, vector<int>(10, 0));
        vector<vector<int>>boxes(9, vector<int>(10, 0));
        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[row].size(); col++){
                if (board[row][col] == '.'){
                    continue;
                }
                int num = board[row][col] - '0';
                int box_check = row / 3 * 3 + col / 3;
                if (rows[row][num] || cols[col][num] || boxes[box_check][num]) {
                    return false;
                }
                rows[row][num] = cols[col][num] = boxes[box_check][num] = 1;
            }
        }
        return true;
    }
};
