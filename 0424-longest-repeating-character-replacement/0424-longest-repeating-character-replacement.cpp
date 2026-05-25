class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int left = 0;
        vector<int> hash(26, 0);
        int maxFreq = 0;
        int n = s.size();
        for(int right = 0; right < n; right++){
            char c = s[right];
            hash[c - 'A']++;
            maxFreq = max(maxFreq, hash[c - 'A']);
            while((right - left + 1) - maxFreq > k){
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};