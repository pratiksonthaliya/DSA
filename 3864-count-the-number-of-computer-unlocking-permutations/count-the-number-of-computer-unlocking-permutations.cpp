class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        long long ans = 1;
        for(long long i=1; i<n; i++){
            if(complexity[0] >= complexity[i]) return 0;
            ans = (ans * i)%MOD;
        }
        
        return ans;
    }
};