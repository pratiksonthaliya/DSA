class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        if(k == 1) return vector<vector<int>> (n-k+1, vector<int>(m-k+1, 0));

        vector<vector<int>> ans(n-k+1, vector<int> (m-k+1, INT_MAX));
        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){

                set<int> st;
                for(int x=i; x<i+k; x++){
                    for(int y=j; y<j+k; y++){
                        st.insert(grid[x][y]);
                    }
                }

                if(st.size() == 1) ans[i][j] = 0;

                int prev = *st.begin();
                for(const int &val : st){
                    if(val != prev){
                        ans[i][j] = min(ans[i][j], val - prev);
                    }
                    prev = val;
                }
            }
        }
        return ans;
    }
};