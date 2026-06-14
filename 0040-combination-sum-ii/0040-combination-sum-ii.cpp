class Solution {
public:
    // void helper(vector<int>& candidates, int target, int ind, int sum, vector<int> &temp, vector<vector<int>> &ans){
    //     if(sum == target){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     if(ind == candidates.size()) return;
    //     if(sum > target) return;
    //     temp.push_back(candidates[ind]);
    //     helper(candidates, target, ind + 1, sum + candidates[ind], temp, ans);
    //     temp.pop_back();
    //     helper(candidates, target, ind + 1, sum, temp, ans);
    // }
    void helper(vector<int>& candidates, int target, int ind, int sum, vector<int> &temp, vector<vector<int>> &ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        // if(ind == candidates.size()) return;
        if(sum > target) return;
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            helper(candidates, target, i + 1, sum + candidates[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, temp, ans);
        return ans;
    }
};