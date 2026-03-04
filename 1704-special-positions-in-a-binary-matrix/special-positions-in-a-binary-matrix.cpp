class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row_f(n, 0), col_f(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]){
                    row_f[i]++;
                    col_f[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1 && row_f[i] == 1 && col_f[j] == 1){
                    ans++;
                }
            }            
        }
        return ans;
    }
};