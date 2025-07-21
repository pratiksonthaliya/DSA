class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    long long dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid){

        long long sum = grid[i][j];
        vis[i][j]=1;
        // sum += grid[i][j];
        
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() 
                   && grid[x][y] != 0 && !vis[x][y]){
                sum += dfs(x, y, vis, grid);
            }
        }

        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int ct=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    
                    long long val = dfs(i, j, vis, grid);

                    if(val%k == 0) ct++;
                }
            }
        }
        
        return ct;
    }
};