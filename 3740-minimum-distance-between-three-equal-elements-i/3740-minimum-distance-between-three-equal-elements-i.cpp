class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it : mpp){
            if(it.second.size() < 3) continue;
            vector<int> temp = it.second;
            for(int i = 2; i < temp.size(); i++){
                int sum = abs(temp[i-2] - temp[i-1])  +abs(temp[i-1] - temp[i]) + abs(temp[i] - temp[i-2]);
                ans = min(ans, sum);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};