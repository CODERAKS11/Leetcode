class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = INT_MIN;
        int n = citations.size();
        for(int h = n; h >= 0; h--){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(citations[j] >= h) count++;
            }
            if(count >= h) ans = max(ans, h);
        }
        return ans;
    }
};