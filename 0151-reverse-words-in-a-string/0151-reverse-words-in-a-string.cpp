class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        string res = "";
        int n = s.size();
        int i = 0;
        
        while(i < n) {
           
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            
            int j = i;
            
            
            while(j < n && s[j] != ' ') j++;
            
            
            string word = s.substr(i, j - i);
            reverse(word.begin(), word.end());
            
            
            if(!res.empty()) res += " ";
            res += word;
            
            i = j;
        }
        
        return res;
    }
};