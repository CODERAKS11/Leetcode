class Solution {
public:
    void generate(vector<int>& nums,  int sum,
                  vector<int> &temp, vector<vector<int>> &ans, int idx){

        
        ans.push_back(temp);
        
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            generate(nums, sum + nums[i], temp, ans, i + 1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        generate(nums, 0, temp, ans, 0);
        return ans;
    }
};