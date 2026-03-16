class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int max_len = (min(n, m) + 1) / 2;
        set<int> st; //min_heap

        for(int len = 0; len <= max_len; len++){

            for(int i=len; i<n-len; i++){
                for(int j=len; j<m-len; j++){

                    // {i, j} -> mid
                    int sum = 0;
                    for(int di = -len; di <= len; di++){
                        for(int dj = -len; dj <= len; dj++){
                            if(abs(di) + abs(dj) == len){ // add only side nodes
                                sum += grid[i+di][j+dj];
                            }
                        }   
                    }

                    st.insert(sum);
                    if(st.size() > 3) st.erase(st.begin());
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};