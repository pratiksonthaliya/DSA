class Solution {
private:
    long long findOps(long long a){
        long long ops = 0;
        long long k = 3;
        long long op = 1;

        while(a > k){
            a -= k;
            ops += (k * op);

            k = k*4;
            op++; 

            // cout << ops << endl;
        }

        ops += a * op;

        // cout << ops << endl;
        return ops ;
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