class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minDist = INT_MAX;
        int n = words.size();
        int i = startIndex;
        if(words[i] == target) return 0;
        int j= startIndex;
        int it = 0;
        while(it <= n - 1){
            if(words[(i + 1) % n] == target){
                minDist = min(minDist, abs(i - startIndex + 1));
                return minDist;
            }
            else if(words[(j - 1 + n) % n] == target){
                minDist = min(minDist, abs(startIndex - j + 1));
                return  minDist;
            }
            else{
                i++;
                j--;
                it++;
            }
        }
        return -1;
    }
};