class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        string ans = "";
        string temp = "";
        int start = i;
        i++;
        while(i < n){
            if(s[i] == ' ' && s[i-1] != ' '){
                temp = s.substr(start, i - start);
                reverse(temp.begin(), temp.end());
                if (!ans.empty()) ans += " ";
                ans += temp;
                while(i < n && s[i] == ' ') i++;
                start = i;
            }
            i++;
        }
        if(start < n){
            temp = s.substr(start);
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += " ";
            ans += temp;
        }
        return ans;
    }
};