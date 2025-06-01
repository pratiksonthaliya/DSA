class Solution {
private:
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& A){
        vis[i][j] = 1;
        
        for(int k=0; k<4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            
            if(ii >= 0 && jj >= 0 && ii < vis.size() && jj < vis[0].size() 
                && !vis[ii][jj] && A[ii][jj] >= A[i][j]){
                dfs(ii, jj, vis, A);
            }
        }    
        
    }        
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        
        vector<vector<bool>> vis1(n, vector<bool> (m, 0));
        vector<vector<bool>> vis2(n, vector<bool> (m, 0));
        
        for(int i=0; i<n; i++){
            dfs(i, 0, vis1, A); // Blue
            dfs(i, m-1, vis2, A); // Red
        }
        
        for(int i=0; i<m; i++){
            dfs(0, i, vis1, A); // Blue
            dfs(n-1, i, vis2, A); // Red
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};