class Solution {
private:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    void fill(int r, int c, int stColor, int color, vector<vector<int>>& image){
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() 
            || image[r][c] != stColor) return;

        image[r][c] = color;
        for(int k=0; k<4; k++){
            fill(r + dr[k], c + dc[k], stColor, color, image);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            fill(sr, sc, image[sr][sc], color, image);
        return image;
    }
};