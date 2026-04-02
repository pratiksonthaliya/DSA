class Solution {
private:
    int n, m;
    vector<vector<int>> coins;
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int left){
        if(i >= n || j >= m) return -1e9;

        if(i == n-1 && j == m-1){
            return (coins[i][j] < 0 && left > 0) ? 0 : coins[i][j];
        }

        if(dp[i][j][left] != INT_MIN) return dp[i][j][left];

        int ans = coins[i][j] + max(solve(i+1, j, left), solve(i, j+1, left));
        if(left > 0 && coins[i][j] < 0){
            ans = max(ans, max(solve(i+1, j, left-1), solve(i, j+1, left-1)));
        }
        return dp[i][j][left] = ans;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (3, INT_MIN)));

        this->dp = dp;
        this->coins = coins;
        return solve(0, 0, 2);
    }
};