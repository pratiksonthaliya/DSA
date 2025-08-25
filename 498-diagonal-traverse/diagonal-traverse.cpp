class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // {{0, 0}} -> --{-1, 1} -> {{0, 1}, {1, 0}} -> --{2, -1} -> {{2, 0}, {1, 1}, {0, 2}} -> --{-1, 3}

        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> ans(m + n - 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        for(int i=0; i<ans.size(); i++){
            if(i&1){
                for(int j=0; j<ans[i].size(); j++){
                    res.push_back(ans[i][j]);
                }
            } else {
                for(int j=ans[i].size()-1; j>=0; j--){
                    res.push_back(ans[i][j]);
                }
            }
        }

        return res;
    }
};