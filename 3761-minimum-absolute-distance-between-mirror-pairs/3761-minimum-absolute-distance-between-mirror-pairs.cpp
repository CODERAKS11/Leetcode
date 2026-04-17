class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num > 0){
            int digit = num % 10;
            ans = ans * 10 + digit;
            num = num / 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int minDist = INT_MAX;

        for(int j = 0; j < n; j++){
            if(mpp.find(nums[j]) != mpp.end()){
                minDist = min(minDist, j - mpp[nums[j]]);
            }
            mpp[reverse(nums[j])] = j;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};