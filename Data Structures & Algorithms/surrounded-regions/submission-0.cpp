class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '1' || board[row][col] == 'X'){
            return;
        }
        board[row][col] = '1';
        dfs(board, row+1, col);
        dfs(board, row, col+1);
        dfs(board, row-1, col);
        dfs(board, row, col-1);
    }
    void solve(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++){
            if (board[row][0] == 'O'){
                dfs(board, row, 0);
            }
            if (board[row][board[0].size()-1] == 'O'){
                dfs(board, row, board[0].size()-1);
            }
        }
        for (int col = 0; col < board[0].size(); col++){
            if (board[0][col] == 'O'){
                dfs(board, 0, col);
            }
            if (board[board.size()-1][col] == 'O'){
                dfs(board, board.size()-1, col);
            }
        }
        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[0].size(); col++){
                if (board[row][col] == 'O'){
                    board[row][col] = 'X';
                }else 
                if (board[row][col] == '1'){
                    board[row][col] = 'O';
                }
            }
        }
    }
};
