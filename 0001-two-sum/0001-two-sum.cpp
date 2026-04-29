class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> oringinal;
        for(int i = 0; i < n; i++){
            oringinal.push_back({nums[i], i});
        }
        sort(oringinal.begin(), oringinal.end());
        int l = 0, r = n - 1;
        while(l < r){
            int sum = oringinal[l].first + oringinal[r].first;
            if(sum == target) return {oringinal[l].second, oringinal[r].second};
            else if(sum < target) l++;
            else r--;
        }
        return {-1,-1};
    }
};