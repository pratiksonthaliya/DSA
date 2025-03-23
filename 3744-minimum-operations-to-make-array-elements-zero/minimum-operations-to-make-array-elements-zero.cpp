class Solution {
private:
    long long findOps(long long n){
        long long y = 1, ops = 0;
        for(int i=1; ; i++){
            if(n <= 0) break;

            long long lo = (1 << (i-1)) * 1LL * (1 << (i-1));
            long long hi = (1 << i) * 1LL * (1 << i) - 1;
            // cout << lo << " " << hi << " " << ops << " " << n << endl;
            if(hi - lo >= n){
                lo = 1;
                hi = n;
            }
            
            ops += (hi - lo + 1) * i;
            n -= (hi - lo + 1);

            // cout << lo << " " << hi << " " << ops << " " << n << endl;
        }
        
        cout << endl;

        return ops;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        // 3 -> 12 * 2 -> 48 * 3 -> 

        long long ans = 0;
        for(auto &q : queries){
            ans += (findOps(q[1]) - findOps(q[0] - 1) + 1) / 2;
        } 

        return ans;
    }
};