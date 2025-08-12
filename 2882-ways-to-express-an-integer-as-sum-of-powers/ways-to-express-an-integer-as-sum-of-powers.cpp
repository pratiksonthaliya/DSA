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

            //cout << num << " ";

            if(num <= n)
                ways = (ways + find(i+1, n - num, x, dp))%MOD;
        }
        //cout << endl;

        return dp[idx][n] = ways;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return find(1, n, x, dp);
    }
};