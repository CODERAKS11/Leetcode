class Solution {
public:
    const int MOD = 1e9 + 7;
    int power(int x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n % 2 == 0) return power(1LL * x * x % MOD, n / 2) % MOD;
        else return (1LL * x * power(x, n - 1)) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        return (1LL * power(5, even) * power(4 , odd)) % MOD;
    }
};