class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> temp(26, 0);
        for(char c : s) temp[c - 'a']++;
        for(char c : t) temp[c - 'a']--;
        for(int d : temp) {
            if(d != 0) return false;
        }
        return true;
    }
};