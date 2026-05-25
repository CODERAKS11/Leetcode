class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int  n = s.size();
        int ans = 0;
        unordered_map<char, int> mpp;
        for(int  right = 0; right < n; right++){
            char c = s[right];
            mpp[c]++;
            while(mpp[c] > 1){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};