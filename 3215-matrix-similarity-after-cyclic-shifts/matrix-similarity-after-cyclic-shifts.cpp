class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        k = k%m;

        vector<vector<int>> new_mat(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                for(int j=0; j<m; j++){
                    new_mat[i][j] = mat[i][(j+k)%m];
                }
            } else {
                for(int j=0; j<m; j++){
                    new_mat[i][j] = mat[i][(j-k + m)%m];
                }
            }

            //check
            for(int j=0; j<m; j++){
                // cout << new_mat[i][j] << " ";
                if(new_mat[i][j] != mat[i][j]) return false;
            }
            // cout << endl;
        }

        return true;
    }
};