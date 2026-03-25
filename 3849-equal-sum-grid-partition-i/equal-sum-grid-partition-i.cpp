class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        long long hsum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                hsum += grid[i][j];
            }
            if(2*hsum == sum) return 1;
        }

        long long vsum = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                vsum += grid[i][j];
            }
            if(2*vsum == sum) return 1;
        }

        return 0;
    }
};