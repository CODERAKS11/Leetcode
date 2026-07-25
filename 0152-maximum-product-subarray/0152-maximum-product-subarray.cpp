class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0], currMax = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if(num < 0){
                swap(currMax, currMin);
            }
           
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);
            
            ans = max(ans, currMax);
        }
        return ans;
    }
};