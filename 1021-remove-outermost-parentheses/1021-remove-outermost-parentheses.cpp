class Solution {
public:
    string removeOuterParentheses(string s) {
        int lvl = 0;
        string ans = "";
        for(char c : s){
            if(c == '('){
                lvl++;
                if(lvl > 1) ans += '(';
            }
            else{
                lvl--;
                if(lvl > 0) ans += ')';
            }
        }
        return ans;
    }
};