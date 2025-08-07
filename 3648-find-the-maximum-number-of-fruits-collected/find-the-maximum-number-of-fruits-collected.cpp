class Solution {
private:
    int n;
    int solve1(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        if(i == n-1 && j == n-1) return 0;
        if(i > n-1 || j > n-1 || i == j) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = fruits[i][j] + max({solve1(i+1, j-1, fruits, dp), solve1(i+1, j, fruits, dp), solve1(i+1, j+1, fruits, dp)}); 
    }

    int tabu(vector<vector<int>>& fruits){
        vector<vector<int>> dp(n, vector<int>(n, -1e9));

        dp[0][n-1] = fruits[0][n-1];
        for(int i=1; i<n-1; i++){
            for(int j = max(n-1-i, i+1); j<n; j++){
                dp[i][j] = fruits[i][j] + max({
                    dp[i-1][j],
                    j-1 >= 0 ? dp[i-1][j-1] : 0, 
                    j+1 < n ? dp[i-1][j+1] : 0
                });
            }
        }

        return dp[n-2][n-1];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        int f1 = tabu(fruits);
        cout << f1 << endl;

        // vector<vector<int>> dp1(n, vector<int>(n, -1));
        // int f1 = solve1(0, n-1, fruits, dp1);

        // swap
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(fruits[i][j], fruits[j][i]);
            }
        }

        int f2 = tabu(fruits);
        cout << f2 << endl;

        // vector<vector<int>> dp2(n, vector<int>(n, -1));
        // int f2 = solve1(0, n-1, fruits, dp2);

        int f3 = 0;
        for(int i=0; i<n; i++){
            f3 += fruits[i][i];
        }

        return f1 + f2 + f3;
    }
};