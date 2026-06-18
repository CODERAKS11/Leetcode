class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();
            st.push(i);
        }
        int largestArea = 0;
        for(int i = 0; i < n; i++){
            largestArea = max(largestArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return largestArea;
    }
};