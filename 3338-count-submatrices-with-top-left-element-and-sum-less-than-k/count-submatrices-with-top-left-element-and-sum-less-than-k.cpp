class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        vector<vector<int>> pre(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                pre[i][j] += grid[i][j] 
                            + (i>0 ? pre[i-1][j] : 0) 
                            + (j>0 ? pre[i][j-1] : 0) 
                            - ((i>0 && j>0) ? pre[i-1][j-1] : 0);
                
                if(pre[i][j] <= k){
                    ans++;
                } 
            }
        }
        return ans;
    }
};