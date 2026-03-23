class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> vals;

            for(int j = 0; j < m; j++){
                if(i > 0 && mat[i][j] != 0) mat[i][j] += mat[i-1][j];
                vals.push_back(mat[i][j]);
            }

            sort(vals.begin(), vals.end());
            for(int j=0; j<vals.size(); j++){
                // cout << vals[j] << " ";
                ans = max(ans, vals[j] * ((int)vals.size() - j));
            }
            // cout << endl;
        }

        return ans;
    }
};

// 1 1 0
// 1 0 1