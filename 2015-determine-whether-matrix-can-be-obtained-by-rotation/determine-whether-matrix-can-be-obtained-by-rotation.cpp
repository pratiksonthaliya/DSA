class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool ans1 = true, ans2 = true, ans3 = true, ans4 = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]){ // Direct Compare
                    ans1 = false;
                }
                if(mat[i][j] != target[j][n-i-1]){ // 90 Degree Clockwise
                    ans2 = false;
                }
                if(mat[i][j] != target[n-j-1][i]){ // 90 Degree Anti-Clockwise / 270 Degree Clockwise
                    ans3 = false;
                }
                if(mat[i][j] != target[n-i-1][n-j-1]){ // 180 Degree Clockwise
                    ans4 = false;
                }
            }
        }

        return (ans1 | ans2 | ans3 | ans4);
    }
};