class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Case 1: Fix i = 0, find farthest j from right
        for(int j = n - 1; j >= 0; j--){
            if(colors[j] != colors[0]){
                maxDist = max(maxDist, j - 0);
                break; // no need to check further
            }
        }

        // Case 2: Fix j = n - 1, find farthest i from left
        for(int i = 0; i < n; i++){
            if(colors[i] != colors[n - 1]){
                maxDist = max(maxDist, (n - 1) - i);
                break; // no need to check further
            }
        }

        return maxDist;
    }
};