class Solution {
public:
    void solve(string s, int ind, int &sign, long long &ans){
        if(ind == s.size() || !isdigit(s[ind])) return;
        int digit = s[ind] - '0';

        if(sign == 1){
            if(ans > INT_MAX / 10 || (ans == INT_MAX/10 && digit > 7)){
                ans = INT_MAX;
                return;
            }
        } else {
            if(ans > INT_MAX / 10 || (ans == INT_MAX/10 && digit > 8 )){
                ans = INT_MIN;
                return;
            }
        }
        ans = ans * 10 + digit;
        solve(s,ind + 1, sign, ans);
    }

    int myAtoi(string s) {
        long long ans = 0;
        int  sign = 1;
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i < n && s[i] == '0') i++;
        solve(s,i,sign,ans);
        return (int) (ans * sign);
    }
};