class Solution {
private:
    bool isValid(int idx, char val, vector<vector<char>>& A){
        int row = idx/9;
        int col = idx%9;
        
        for(int i=0; i<9; i++){
            if(A[row][i] == val) return false;
            if(A[i][col] == val) return false;
        }
        
        int box_r = row/3, box_c = col/3;
        
        int box_r_st = box_r * 3, box_c_st = box_c * 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(A[box_r_st + i][box_c_st + j] == val) return false;
            }
        }
        
        return true;
    }
    void solve(int idx, vector<vector<char>>& A, vector<vector<int>>& vis, vector<vector<char>>& ans){
        if(idx == 81){
            ans = A;
            return;
        }
        
        int row = idx/9;
        int col = idx%9;
        
        if(vis[row][col] == 1) {
            solve(idx+1, A, vis, ans);
            return;
        }
        
        for(char val='1'; val<='9'; val++){
            if(isValid(idx, val, A)){
                A[row][col] = val;
                solve(idx+1, A, vis, ans);
                A[row][col] = '.';
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& A) {
        vector<vector<int>> vis(9, vector<int> (9, 0));
        vector<vector<char>> ans(9, vector<char> (9, '.'));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(A[i][j] != '.') vis[i][j] = 1;
            }
        }
        
        solve(0, A, vis, ans);
        A = ans;
    }
};