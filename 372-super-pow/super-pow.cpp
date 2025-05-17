class Solution {
private:
    const int M = 1337;
    int binExp(int a, int b){
        a = a%M;

        int ans = 1;
        while(b){
            if(b&1){
                ans = (ans * 1LL * a)%M;
            }
            a = (a * 1LL * a)%M;
            b = b>>1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        a = a%M;

        int ETF = 1140; // 1337 * (1 - 1/7) * (1 - 1/191)

        int bmod = 0;
        for(int val : b){
            bmod = (bmod*10 + val)%ETF;
        }

        if(bmod == 0) bmod += ETF;
        return binExp(a, bmod);
    }
};