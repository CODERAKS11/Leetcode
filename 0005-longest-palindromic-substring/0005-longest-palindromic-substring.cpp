class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int start = 0;
        for(int c = 0; c < 2 * n - 2; c++){
            int left = c / 2;
            int right = left + (c % 2);
            while(left >= 0 && right < n && s[left] == s[right]){
                int len = right - left + 1;
                if(len > maxLen){
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
    }
};