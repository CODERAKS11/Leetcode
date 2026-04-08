class Solution {
public:
const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // unordered_map<int, int> mpp;
        // for(int i = 0; i < nums; i++) {
        //     mpp[i] = nums[i];
        // }
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            int idx = l;
            long long temp = 0;
            while(idx <= r){
                temp = (1LL * nums[idx] * v) % MOD;
                nums[idx] = temp;
                idx += k;
            }
        }
        int ans = 0;
        for(int it : nums) ans ^= it;
        return ans;
    }
};