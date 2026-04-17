class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int ans = 0;
        int i = 0;
        int n = s.size();
        while(s[i] == ' ') i++;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') neg = true;
            i++;
        }
        if(i >= n || !isdigit(s[i])) return 0;
        while(s[i] == '0') i++;
        while(i < n){
            int digit = s[i] - '0';
            if(!isdigit(s[i])) break;
            if(ans > (INT_MAX - digit) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return neg ? -1 * ans : ans;
    }
};