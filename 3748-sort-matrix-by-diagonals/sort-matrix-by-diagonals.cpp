class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int j=1; j<2*n; j++){
            vector<int> temp;
            int x = max(n - j, 0), y = max(j - n, 0);
            // cout << x << " " << y << " -> ";
            while(x < n && y < n){
                temp.push_back(grid[x][y]);
                x++; y++;
            }

            x = max(n - j, 0), y = max(j - n, 0);
            if(x < y) sort(temp.begin(), temp.end());
            else sort(temp.rbegin(), temp.rend());

            int i = 0;
            while(x < n && y < n && i < temp.size()){
                grid[x][y] = temp[i];
                x++; y++; i++;
            }
            // for(int val : temp) cout << val << " ";
            // cout << endl;
        }

        return grid;
    }
};