class Solution {
private:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool dfs(int i, int j, int p_i, int p_j, int len, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[i][j] = 1;

        for(int k=0; k<4; k++){
            int ii = i + dx[k], jj = j + dy[k];
            
            if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

            if (grid[ii][jj] != grid[i][j]) continue;

            if(!vis[ii][jj]){
                if(dfs(ii, jj, i, j, len+1, grid, vis))
                    return true;
            } else if(ii != p_i && jj != p_j){
                return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(dfs(i, j, -1, -1, 1, grid, vis)) return true;
                }
            }
        }
        return false;
    }
};

// bac
// cac
// ddc
// bcc