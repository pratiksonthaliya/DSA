class Solution {
private:
    int n, m;
    int solve(int i, int j, int left, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return -1e9;

        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && left > 0) return 0;
            return coins[i][j];
        }

        if(dp[i][j][left] != INT_MIN) return dp[i][j][left];

        int ans = 0;
        if(coins[i][j] >= 0){
            ans = coins[i][j] + max(solve(i+1, j, left, coins, dp), solve(i, j+1, left, coins, dp));
        } else {

            if(left > 0){
                ans = max(max(solve(i+1, j, left-1, coins, dp), solve(i, j+1, left-1, coins, dp)), 
                       coins[i][j] + max(solve(i+1, j, left, coins, dp), solve(i, j+1, left, coins, dp)));
            } else {
                ans = coins[i][j] + max(solve(i+1, j, left, coins, dp), solve(i, j+1, left, coins, dp));
            }
        }
        return dp[i][j][left] = ans;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (3, INT_MIN)));
        return solve(0, 0, 2, coins, dp);
    }
};