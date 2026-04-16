class Solution {
public:
    int maxDepth(string s) {
        int lvl = 0;
        int maxLvl = INT_MIN;
        for(char c : s){
            if(c == '(') lvl++;
            else if(c == ')') lvl--;
            maxLvl = max(maxLvl, lvl);
        }
        return maxLvl;
    }
};