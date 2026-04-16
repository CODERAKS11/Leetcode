class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        int n = strs.size();
        for(int i = 0; i < n; i++){
            int j = 0;
            while(j < temp.size() && temp[j] == strs[i][j]) j++;
            if(j == 0) temp = "";
            else temp = temp.substr(0, j);
        }
        return temp;
    }
    
};