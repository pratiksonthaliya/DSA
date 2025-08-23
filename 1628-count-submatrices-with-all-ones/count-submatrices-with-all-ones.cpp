class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dp_row(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    dp_row[i][j] = mat[i][j];
                    if(i > 0) dp_row[i][j] += dp_row[i-1][j];
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int len = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] > 0){
                    len++;
                    
                    ans += len; // horizontal
                    ans += (dp_row[i][j] - 1); // vertical
                    
                } else {
                    len = 0;
                }

                //rect
                int mini = dp_row[i][j];
                for(int k=j-1; k>=0; k--){
                    mini = min(dp_row[i][k], mini);

                    if(mini > 1) ans += (mini - 1);
                    else break;
                }
            }
        }

        return ans;
    }
};