class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<long long>> minProd(n, vector<long long> (m, LLONG_MAX));
        vector<vector<long long>> maxProd(n, vector<long long> (m, LLONG_MIN));

        minProd[0][0] = maxProd[0][0] = grid[0][0];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(i == 0 && j == 0) continue;

                if(i > 0) {
                    minProd[i][j] = min(minProd[i][j], min(1LL*minProd[i-1][j]*grid[i][j], 1LL*maxProd[i-1][j]*grid[i][j]));
                    maxProd[i][j] = max(maxProd[i][j], max(1LL*minProd[i-1][j]*grid[i][j], 1LL*maxProd[i-1][j]*grid[i][j]));
                }

                if(j > 0){
                    minProd[i][j] = min(minProd[i][j], min(1LL*minProd[i][j-1]*grid[i][j], 1LL*maxProd[i][j-1]*grid[i][j]));
                    maxProd[i][j] = max(maxProd[i][j], max(1LL*minProd[i][j-1]*grid[i][j], 1LL*maxProd[i][j-1]*grid[i][j]));
                }
            }
        }

        long long ans = max(minProd[n-1][m-1], maxProd[n-1][m-1]);
        return (ans < 0 ? -1 : ans%MOD);
    }
};