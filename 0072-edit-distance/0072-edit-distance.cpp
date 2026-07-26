class Solution {
public:
    int find(string word1, string word2, int m, int n, vector<vector<int>> &memo){
        if(m == 0 ) return n;
        if(n == 0) return m;
        if(memo[m][n] != -1) return memo[m][n];
        if(word1[m-1] == word2[n-1]){
            return memo[m][n] = find(word1, word2, m - 1, n - 1, memo);
        } 
        return memo[m][n] = min({1 + (memo[m][n-1] == -1 ? find(word1 , word2, m, n -1, memo) : memo[m][n-1]),
         1 + (memo[m-1][n] == -1 ? find(word1, word2, m - 1, n, memo) : memo[m-1][n]),
         1 + (memo[m-1][n-1] == -1 ? find(word1, word2, m - 1, n - 1, memo) : memo[m-1][n-1])
        });
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return find(word1, word2, m, n, memo);
        
    }
};