class Solution {
private:
    vector<vector<int>> dirs = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    double solve(int a, int b, vector<vector<double>>& dp){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];

        double ans = 0.0;
        for(auto dir : dirs){
            ans += solve(a - dir[0], b - dir[1], dp);
        }
        return dp[a][b] = ans/4;
    }
public:
    double soupServings(int n) {
        if(n > 4300) return 1.0;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return solve(n, n, dp);
    }
};