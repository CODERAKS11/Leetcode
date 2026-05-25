class Solution {
public:
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = pse(heights);
        vector<int> next = nse(heights);
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            res = max(res, heights[i] * (next[i] - prev[i] - 1));
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n,0);
        int ans = 0;
        for(auto row : matrix){
            for(int i = 0; i < row.size(); i++){
                if(row[i] == '1') heights[i]++;
                else heights[i] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};