class Solution {
public:
    int findLCS(string text1, string text2, int m, int n, vector<vector<int>> &memo){
        if(m == 0 || n == 0) return 0;
        if(text1[m-1] == text2[n-1]) {
            if(memo[m-1][n-1] != -1) return 1 + memo[m-1][n-1];
            return memo[m][n] =  1 + findLCS(text1, text2, m - 1, n - 1, memo);
        }
        return memo[m][n] =  max(memo[m][n-1] == -1 ? findLCS(text1, text2, m, n-1, memo) : memo[m][n-1], memo[m - 1][n] == -1 ? findLCS(text1, text2, m - 1, n, memo) : memo[m-1][n]);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1,-1));
        return findLCS(text1, text2, m, n, memo);
    }
};