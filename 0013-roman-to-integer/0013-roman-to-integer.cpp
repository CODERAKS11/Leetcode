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
        int ans = 0;
        int n = s.size();
        int curr = n-2, prev = n-1;
        while(curr >= 0 && prev >= 0){
            char prevChar = s[prev];
            char currChar = s[curr];
            int digit = 0;
            if((prevChar == 'V' && currChar == 'I') 
            || (prevChar == 'X' && currChar == 'I')){
                digit = mpp[prevChar] - 1;
                prev -= 2;
                curr -= 2;
            }
            else if((prevChar == 'L' && currChar == 'X') 
            || (prevChar == 'C' && currChar == 'X')){
                digit = mpp[prevChar] - 10;
                prev -= 2;
                curr -= 2;
            }
            else if((prevChar == 'D' && currChar == 'C') 
            || (prevChar == 'M' && currChar == 'C')){
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
        if(prev >= 0){
            return ans + mpp[s[prev]];
        }
        return ans;
    }
};