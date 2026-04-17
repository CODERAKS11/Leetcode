class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0,maxLen = 1, n = s.size();
        for(int c = 0; c < 2*n - 2; c++){
            int left = c / 2;
            int right = left + (c%2);
            while(left >= 0 && right < n && s[left] == s[right]){
                int len = right - left + 1;
                if(len > maxLen){
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
            
        }
        return s.substr(start,maxLen);
    }
};