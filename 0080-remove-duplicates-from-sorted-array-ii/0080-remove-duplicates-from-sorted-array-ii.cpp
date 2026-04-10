class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > 2) count++;
            nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};