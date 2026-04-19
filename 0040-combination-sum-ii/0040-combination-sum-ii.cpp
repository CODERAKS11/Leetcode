class Solution {
public:
    void generate(vector<int>& candidates, int target, int sum,
                  vector<int> &temp, vector<vector<int>> &ans, int idx){

        // Base case
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){

            // Skip duplicates
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            // Pruning
            if(sum + candidates[i] > target) break;

            temp.push_back(candidates[i]);
            generate(candidates, target, sum + candidates[i], temp, ans, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        generate(candidates, target, 0, temp, ans, 0);
        return ans;
    }
};