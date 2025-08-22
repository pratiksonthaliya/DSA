class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    minX = min(minX, j);
                    minY = min(minY, i);

                    maxX = max(maxX, j);
                    maxY = max(maxY, i);
                }
            }
        }

        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};