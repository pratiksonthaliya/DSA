class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool ans = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]){
                    ans = false;
                }
            }
        }
        if(ans) return ans;

        ans = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[j][n-i-1]){
                    ans = false;
                }
            }
        }
        if(ans) return ans;

        ans = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[n-j-1][i]){
                    ans = false;
                }
            }
        }
        if(ans) return ans;

        ans = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[n-i-1][n-j-1]){
                    ans = false;
                }
            }
        }
        if(ans) return ans;

        return false;
    }
};