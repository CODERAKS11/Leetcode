class Solution {
public:
    double power(double x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n % 2 == 0) return power(x * x, n / 2);
        else return x * power(x, n - 1);
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            N = -1 * N;
            x = 1.0 / x;
        }
        return power(x,N);
    }
};