class Solution {
public:
    const int MOD = 1e9 + 7;
    int invMOD(int num){
        return binExp(num, MOD - 2);
    }
    int binExp(long long num, int pow){
        if(num == 1 || pow == 0){
            return 1;
        }

        long long k = binExp(num, pow/2)%MOD;
        if(pow&1){
            return ((k * k)%MOD * num)%MOD;
        } else {
            return (k * k)%MOD;
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        for(int i=0; i<31; i++){
            if((n>>i)&1){
                pows.push_back(1<<i);
            }
        }

        vector<long long> pre(pows.size()+1, 1);
        for(int i=0; i<pows.size(); i++){
            pre[i+1] = (1LL * pre[i] * pows[i])%MOD;
        }

        vector<int> ans;
        for(auto q : queries){
            ans.push_back((pre[q[1]+1] * invMOD(pre[q[0]]))%MOD);
        }

        return ans;
    }   
};