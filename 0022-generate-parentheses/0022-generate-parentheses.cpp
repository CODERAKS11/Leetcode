class Solution {
public:
    void generate(int n, vector<string> &ans, string temp, int countOpen, int countClose){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
            return;
        }
        if(countOpen < n){
            generate(n, ans, temp + '(', countOpen + 1, countClose);
        }
        if(countClose < countOpen){
            generate(n, ans, temp + ')', countOpen, countClose + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, ans, "", 0, 0);
        return ans;
    }
};