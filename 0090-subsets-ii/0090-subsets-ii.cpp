class Solution {
public:
    void helper(vector<int>& nums, int ind, vector<int> &temp, set<vector<int>> &res){
        if(ind == nums.size()){
            res.insert(temp);
            return;
        }
        helper(nums, ind + 1, temp, res);
        temp.push_back(nums[ind]);
        helper(nums, ind + 1, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, 0, temp, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};