class Solution {
public:
    void solve(int n,string &ans){
        if(n == 0) return;
        string temp = "";
        int l = 0;
        char curr = ans[l];
        for(int r = 0; r < ans.size(); r++){
            if(ans[r] != curr){
                temp += (r - l) + '0';
                temp += curr;
                curr = ans[r];
                l = r;
            }
        }
        temp += to_string(ans.size() - l);
        temp += curr;
        ans = temp;
        return solve(n-1, ans);
    }
    string countAndSay(int n) {
        string ans = "1";
        solve(n - 1, ans);
        return ans;
    }
};