class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        int maxLen = 0;
        unordered_set<char> st;
        for(int r = 0; r < n; r++){
            char c = s[r];
            while(!st.empty() && st.find(c) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(c);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};