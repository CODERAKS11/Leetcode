class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(auto temp : matrix){
            int low = 0;
            int high = temp.size() - 1;
            if(target < temp[low] || target > temp[high]) continue;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(temp[mid] == target) return true;
                else if(temp[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};