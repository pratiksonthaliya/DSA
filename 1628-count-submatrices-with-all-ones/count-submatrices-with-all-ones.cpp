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
                cout << dp_row[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

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

            //cout << "Row " + i << " : " << ans << endl;
        }

        // vector<vector<int>> dp_col(n, vector<int> (m, 0));
        // for(int j=0; j<m; j++){
        //     for(int i=0; i<n; i++){
        //         if(mat[i][j] == 1){
        //             dp_col[i][j] = mat[i][j];
        //             if(j > 0) dp_col[i][j] += dp_col[i][j-1];
        //         }
        //     }
        // }

        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << dp_col[i][j] << " ";
        //         if(mat[i][j] > 0){
        //             ans += dp_row[i][j] + dp_col[i][j] - 1;
        //             if(i > 0 && j > 0 && mat[i-1][j-1] == 1 && mat[i-1][j] == 1 && mat[i][j-1] == 1) ans++;
        //         }
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};