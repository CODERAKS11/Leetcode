class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        long long N = n;
        double result = 1.0;
        if(N < 0){
            N = -N;
            x = 1 / x;
        }
        while(N > 0){
            if(N % 2 == 1){
                result *= x;
                N = N-1;
            }
            else{
                x = x * x;
                N = N / 2;
            }
        }
        return result;
    }
};