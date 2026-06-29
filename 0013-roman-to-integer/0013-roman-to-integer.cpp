class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int n = s.size();
        int prev = n - 1;
        int curr = n - 2;
        int ans = 0;

        while(prev >= 0 && curr >= 0){
            char prevChar = s[prev];
            char currChar = s[curr];
            int digit = 0;
            if((currChar == 'I' && prevChar == 'V') || (currChar == 'I' && prevChar == 'X')){
                digit = mpp[prevChar] - 1;
                prev -= 2;
                curr -= 2;
            }
            else if((currChar == 'X' && prevChar == 'L') || (currChar == 'X' && prevChar == 'C')){
                digit = mpp[prevChar] - 10;
                prev -= 2;
                curr -= 2;
            }
            else if((currChar == 'C' && prevChar == 'D') || (currChar == 'C' && prevChar == 'M')){
                digit = mpp[prevChar] - 100;
                prev -= 2;
                curr -= 2;
            }
            else{
                digit = mpp[prevChar];
                prev--;
                curr--;
            }
            ans += digit;
        }
        if(prev >= 0) ans += mpp[s[prev]];
        return ans;
    }
};