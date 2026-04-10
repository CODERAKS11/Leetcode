class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int element = -1;
        int shift = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != element){
                element = nums[i];
                count = 0;
            }
            count++;
            if(count > 2) shift++;
            nums[i - shift] = nums[i];
        }
        return nums.size() - shift;
    }
};