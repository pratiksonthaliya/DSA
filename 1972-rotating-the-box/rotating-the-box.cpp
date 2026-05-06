class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char> (n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = box[n-1-j][i];
            }
        }
        
        for(int j=0; j<n; j++){
            for(int i=m-1; i>=0; i--){
                if(ans[i][j] == '.'){
                    for(int k=i-1; k>=0; k--){
                        if(ans[k][j] == '*') break;
                        else if(ans[k][j] == '#'){
                            swap(ans[k][j], ans[i][j]);
                            break;
                        } 
                    }
                }
            }
        }
        return ans;
    }
};