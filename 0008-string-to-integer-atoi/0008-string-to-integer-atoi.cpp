class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return 0;

        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};