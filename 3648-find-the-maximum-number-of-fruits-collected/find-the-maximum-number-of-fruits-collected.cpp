class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int solve1(int i, int j, vector<vector<int>>& fruits){
        if(i == n-1 && j == n-1) return 0;
        if(i > n-1 || j > n-1 || i == j) return -1e9;
        // if(i >= n/2 && j < (n+1)/2) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = fruits[i][j] + max({solve1(i+1, j-1, fruits), solve1(i+1, j, fruits), solve1(i+1, j+1, fruits)}); 
    }
    int solve2(int i, int j, vector<vector<int>>& fruits){
        if(i == n-1 && j == n-1) return 0;
        if(i > n-1 || j > n-1 || (i == j)) return -1e9;
        // if(i < (n+1)/2 && j >= n/2) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = fruits[i][j] + max({solve2(i-1, j+1, fruits), solve2(i, j+1, fruits), solve2(i+1, j+1, fruits)}); 
    }
    // int solve3(int i, int j, vector<vector<int>>& fruits){
    //     if(i == (n+1)/2 - 1 && j == (n+1)/2 - 1) return 0;
    //     if(i >= (n+1)/2 || j >= (n+1)/2) return -1e9;

    //     return fruits[i][j] + max({solve3(i, j+1, fruits), solve3(i+1, j+1, fruits), solve3(i+1, j, fruits)}); 
    // }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        dp = dp1;
        int f1 = solve1(0, n-1, fruits);

        vector<vector<int>> dp2(n, vector<int>(n, -1));
        dp = dp2;
        int f2 = solve2(n-1, 0, fruits);

        //int f3 = solve3(0, 0, fruits);

        int f3 = 0;
        for(int i=0; i<n; i++){
            f3 += fruits[i][i];
        }

        cout << f1 << " " << f2 << " " << f3 << endl;

        return f1 + f2 + f3;
    }
};