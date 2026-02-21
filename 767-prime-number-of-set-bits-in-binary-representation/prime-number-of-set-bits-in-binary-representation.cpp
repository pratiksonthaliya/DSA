class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        vector<bool> isPrime(32, 1);
        isPrime[0] = isPrime[1] = 0;
        for(int i=3; i<32; i++){
            for(int j=2; j*j<=i; j++){
                if(i%j == 0) isPrime[i] = 0;
            }
        } 

        int ans = 0;
        for(int num=left; num<=right; num++){
            int ct = __builtin_popcount(num);
            if(isPrime[ct]) ans++;
        }
        return ans;
    }
};