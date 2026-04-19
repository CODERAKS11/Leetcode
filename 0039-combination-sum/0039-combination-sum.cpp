class Solution {
public:
    void generate(vector<int>& candidates, int target, long long sum, vector<int> &temp,vector<vector<int>> &ans, int idx){
        if(idx == candidates.size() || sum == target){
            if(sum == target) ans.push_back(temp);
            return;
        }
        
        if(sum < target){
            temp.push_back(candidates[idx]);
            generate(candidates, target, sum + candidates[idx], temp, ans, idx);
            temp.pop_back();
        }
        
        generate(candidates, target, sum, temp, ans, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        generate(candidates, target, sum, temp, ans, 0);
        return ans;
    }
};