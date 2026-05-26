class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        for(char c : t){
            hash[c]++;
        }
        int count = 0;
        int m = t.size();
        int sInd = -1;
        int minLen = INT_MAX;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            hash[s[right]]--;
            if(hash[s[right]] >= 0) count++;
            while(count == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sInd = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) count--;
                left++;
            }
        }
        return sInd == -1 ? "" : s.substr(sInd, minLen);
    }
};