class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int val, int row, int col){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][col] == val + '0') return false;
            if(board[row][i] == val + '0') return false;
        }

        int rowStart = 3 * (row / 3);
        int colStart = 3 * (col / 3);
        for(int i = rowStart; i < rowStart + 3; i++){
            for(int j = colStart; j <  colStart + 3; j++){
                if((board[i][j] - '0') == val) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int val = 1; val <= 9; val++){
                        if(isSafe(board, val, i, j)) {
                            board[i][j] = val + '0';
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};