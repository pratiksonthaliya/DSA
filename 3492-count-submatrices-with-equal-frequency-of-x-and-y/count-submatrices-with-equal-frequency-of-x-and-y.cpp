class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dpX(n, vector<int> (m, 0));
        vector<vector<int>> dpY(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dpX[i][j] = (grid[i][j] == 'X' ? 1 : 0); 
                dpY[i][j] = (grid[i][j] == 'Y' ? 1 : 0); 

                dpX[i][j] += ((i!=0) ? dpX[i-1][j] : 0) + ((j!=0) ? dpX[i][j-1] : 0) - ((i!=0 && j!=0) ? dpX[i-1][j-1] : 0);
                dpY[i][j] += ((i!=0) ? dpY[i-1][j] : 0) + ((j!=0) ? dpY[i][j-1] : 0) - ((i!=0 && j!=0) ? dpY[i-1][j-1] : 0);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dpX[i][j] == dpY[i][j] && dpX[i][j] != 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};