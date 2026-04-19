class Solution {
public:
    void generate(int ind, string digits, string temp, vector<string> &ans, unordered_map<int, string> &mpp){
        if(ind == digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < mpp[digit].size() ; i++){
            generate(ind+1 , digits, temp + mpp[digit][i], ans, mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        unordered_map<int, string> mpp;
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        generate(0, digits, temp, ans, mpp);
        return ans;
    }
};