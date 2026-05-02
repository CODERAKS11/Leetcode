class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            int temp = i;
            long long num = 0;
            bool invalid = false;
            bool changed = false;
            while(temp > 0){
                int digit = temp % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    invalid = true;
                    break;
                }
                 if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                    changed = true;
                }
                temp /= 10;
            }
            if(!invalid && changed) count++;
        }
        return count;
    }
};