class Solution {
private:
    int n, m;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    void fill(int r, int c, int stColor, int color, vector<vector<int>>& image){
        if(r < 0 || c < 0 || r >= n || c >= m || image[r][c] != stColor || image[r][c] == color) return;

        //cout << stColor << endl;

        image[r][c] = color;

        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            fill(nr, nc, stColor, color, image);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        fill(sr, sc, image[sr][sc], color, image);
        return image;
    }
};