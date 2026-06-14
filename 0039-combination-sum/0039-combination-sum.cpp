class Solution {
public:
    void helper(vector<int>& nums, int target, int ind, vector<int> &temp, vector<vector<int>> &ans, int sum){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        
        if(sum > target) return;

        for(int i = ind; i < nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums, target, i , temp, ans, sum + nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, 0, temp, ans, 0);
        return ans;
    }
};