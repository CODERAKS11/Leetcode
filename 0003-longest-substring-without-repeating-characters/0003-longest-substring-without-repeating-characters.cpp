class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        if(n == 1) return 1;
        int l = 0;
        unordered_map<char, int> mpp;
        for(int r = 0; r < n; r++){
            char c = s[r];
            if(mpp.find(c) != mpp.end()){
                l = max(l, mpp[c]+1);
            }
            mpp[c] = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};