class Solution {
public:
    void generate( int k, int n,  int sum,
                  vector<int> &temp, vector<vector<int>> &ans, int idx){

        // Base case
        if(temp.size() == k){
            if(sum == n) ans.push_back(temp);
            return;
        }

        for(int i = idx; i <= 9; i++){
            // Pruning
            if(sum + i > n) break;

            temp.push_back(i);
            generate(k,n, sum + i, temp, ans, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(k,n,  0, temp, ans, 1);
        return ans;
    }
};