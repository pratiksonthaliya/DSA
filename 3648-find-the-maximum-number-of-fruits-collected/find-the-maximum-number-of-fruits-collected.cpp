class Solution {
private:
    int n;
    int solve1(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        if(i == n-1 && j == n-1) return 0;
        if(i > n-1 || j > n-1 || i == j) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = fruits[i][j] + max({solve1(i+1, j-1, fruits, dp), solve1(i+1, j, fruits, dp), solve1(i+1, j+1, fruits, dp)}); 
    }
    int solve2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        if(i == n-1 && j == n-1) return 0;
        if(i > n-1 || j > n-1 || (i == j)) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = fruits[i][j] + max({solve2(i-1, j+1, fruits, dp), solve2(i, j+1, fruits, dp), solve2(i+1, j+1, fruits, dp)}); 
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int f1 = solve1(0, n-1, fruits, dp1);

        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int f2 = solve2(n-1, 0, fruits, dp2);

        int f3 = 0;
        for(int i=0; i<n; i++){
            f3 += fruits[i][i];
        }

        return f1 + f2 + f3;
    }
};