class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int n = complexity.size();

        for(int i=1; i<n; i++){
            if(complexity[0] >= complexity[i]) return 0;
        }

        long long ans = 1;
        for(long long i=2; i<n; i++){
            ans = (ans * i)%MOD;
        }
        return ans;
    }
};