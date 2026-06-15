class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col){
        int n = board.size();
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }
        int r = row, c = col;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row, c = col;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int n,int col, vector<string> &board, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                solve(n, col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string temp = "";
        for(int i = 0; i < n; i++) temp += '.';
        for(int i = 0; i < n; i++){
            board[i] = temp;
        }
        solve(n, 0, board, ans);
        return ans;
    }
};