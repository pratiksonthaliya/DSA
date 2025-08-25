class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> ans(m + n - 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size(); j++){
                int idx = j;
                if(!(i&1)) idx = ans[i].size() - 1 - j;
                res.push_back(ans[i][idx]);
            }
        }

        return res;
    }
};