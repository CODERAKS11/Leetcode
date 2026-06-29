#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int n = strs.size();
        for(int i = 1; i < n; i++){
            string temp = strs[i];
            int j = 0;
            int k = 0;
            while(j < pre.size() && k < temp.size() && pre[j] == temp[k]){
                j++;
                k++;
            }
            pre = pre.substr(0, j);
        }
        return pre;
    }
};