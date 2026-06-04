class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i = num1; i <= num2; i++){
            vector<int> temp;
            int j = i;
            while(j > 0){
                int d = j % 10;
                temp.push_back(d);
                j = j / 10;
            }
            reverse(temp.begin(), temp.end());
            for(int j = 1; j < temp.size() - 1; j++){
                if((temp[j] > temp[j - 1]) && (temp[j] > temp[j + 1])) cnt++;
                if((temp[j] < temp[j - 1]) && (temp[j] < temp[j + 1])) cnt++;
            }
        }
        return cnt;
    }
};