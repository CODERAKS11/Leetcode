class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        // Check all rows in current column
        for (int i = 0; i < 9; i++) {
            // If character already exists in column, not valid
            if (board[i][col] == c)
                return false;
        }

        // Check all columns in current row
        for (int j = 0; j < 9; j++) {
            // If character already exists in row, not valid
            if (board[row][j] == c)
                return false;
        }

        // Calculate start indices of the 3x3 sub-box
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        // Check the 3x3 sub-box for duplicate character
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If character found in sub-box, not valid
                if (board[boxRowStart + i][boxColStart + j] == c)
                    return false;
            }
        }

        // If all checks passed, placement is valid
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, row, col, c)){
                            board[row][col] = c;
                            if(solve(board)) return true;
                            board[row][col] = '.';
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