class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<bool>& visited) {
        int n = arr.size();

        if (start < 0 || start >= n || visited[start]) return false;
        if (arr[start] == 0) return true;

        visited[start] = true;

        return dfs(arr, start + arr[start], visited) ||
               dfs(arr, start - arr[start], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};