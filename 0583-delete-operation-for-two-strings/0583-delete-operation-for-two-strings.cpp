class Solution {
public:
    
    int findLCS(string word1, string word2, int m, int n, vector<vector<int>> &memo){
        if(m == 0 || n == 0) return 0;
        if(word1[m-1] == word2[n-1]){
            if(memo[m][n] != -1) return memo[m][n];
            return memo[m][n] = 1 + findLCS(word1, word2, m - 1, n - 1, memo);
        } 
        return memo[m][n] = max(memo[m][n-1] == -1 ? findLCS(word1, word2, m, n -1, memo) : memo[m][n-1], memo[m-1][n] == -1 ? findLCS(word1, word2, m - 1, n, memo) : memo[m-1][n]);
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        int common = findLCS(word1, word2, m, n, memo);
        return  (m - common) + (n - common);
    }
};