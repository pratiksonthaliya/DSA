class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size(), m = grid[0].size();

        for(int j=y; j<y+k; j++){

            // x, x + 1, ... x + k -1 -1,  x + k - 1
            // i + x, i+1+x, .... x + k - 1 
            
            for(int i=0; i<(k+1)/2; i++){
                swap(grid[i+x][j], grid[x + k - 1 - i][j]);
            }
        }

        return grid;
    }
};