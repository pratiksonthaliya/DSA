class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i=0; i<mat.size(); i++){
            bool has1 = false;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]){
                    
                    if(has1){
                        has1 = false;
                        break;
                    }
                    has1 = true;

                    int ct = 0;
                    for(int k=0; k<mat.size(); k++){
                        if(mat[k][j]){
                            ct++;
                            if(ct > 1) break;
                        }
                    }

                    if(ct > 1){
                        has1 = false;
                        break;
                    }
                }
            }
            if(has1) ans++;
        }

        return ans;
    }
};