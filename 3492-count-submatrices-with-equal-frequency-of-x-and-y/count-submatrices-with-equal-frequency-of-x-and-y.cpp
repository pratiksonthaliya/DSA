class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = (grid[i][j] == 'X' ? 1 : (grid[i][j] == 'Y' ? -1 : 0)); 
                dp[i][j] += ((i!=0) ? dp[i-1][j] : 0) + ((j!=0) ? dp[i][j-1] : 0) - ((i!=0 && j!=0) ? dp[i-1][j-1] : 0);
            }
        }

        int ans = 0;
        vector<bool> seenAny(m, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(j != 0) seenAny[j] = seenAny[j] || seenAny[j-1];
                if(grid[i][j] != '.') seenAny[j] = true;

                if(dp[i][j] == 0 && seenAny[j]) ans++;
            }
        }

        return ans;
    }
};