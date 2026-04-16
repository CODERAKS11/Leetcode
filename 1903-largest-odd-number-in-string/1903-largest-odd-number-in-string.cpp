class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n-1;
        int ans = INT_MIN;
        string res = "";
        while(i >= 0){
            if((num[i] - '0') % 2  == 0) i--;
            else{
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};