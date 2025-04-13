class Solution {
private:
    const int MOD = 1e9 + 7;
    long long int binExp(int x, long long int n){ // x^n
        if(n == 0) return 1;

        long long int k = binExp(x, n/2)%MOD;
        if(n%2 == 1) return (x * k * k)%MOD;
        return (k*k)%MOD;
    }
public:
    int countGoodNumbers(long long n) {
        // 5 ^ (n+1)/2  *  4 ^ (n/2)
        return (binExp(5, (n+1)/2)%MOD * binExp(4, n/2)%MOD )%MOD;
    }
};