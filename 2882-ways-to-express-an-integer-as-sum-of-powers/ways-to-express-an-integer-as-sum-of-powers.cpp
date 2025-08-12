class Solution {
private:
    const int MOD = 1e9 + 7;
    int find(int idx, int n, int x, vector<vector<int>> &dp){
        if(n == 0) return 1;

        if(dp[idx][n] != -1) return dp[idx][n];
        
        int ways = 0;
        for(int i=idx; i<=n; i++){
            long int num = 1;
            for(int j=1; j<=x; j++) num *= i; 

            if(num <= n)
                ways = (ways + find(i+1, n - num, x, dp))%MOD;
        }

        return dp[idx][n] = ways;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            long long val = pow(i, x);
            for(int j=0; j<=n; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= val){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-val])%MOD;
                }
            }
        }

        return dp[n][n];
    }
};