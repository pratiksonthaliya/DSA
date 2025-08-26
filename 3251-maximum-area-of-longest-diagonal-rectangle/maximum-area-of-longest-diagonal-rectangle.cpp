class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_sq_diag = 0;
        for(auto d : dimensions){
            max_sq_diag = max(max_sq_diag, d[0]*d[0] + d[1]*d[1]);
        }

        int max_area = 0;
        for(auto d : dimensions){
            int new_sq_diag = d[0]*d[0] + d[1]*d[1];
            if(new_sq_diag == max_sq_diag){
                max_area = max(max_area, d[0]*d[1]);
            }
        }

        return max_area;
    }
};