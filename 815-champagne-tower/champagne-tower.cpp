class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> left = {poured*1.0};
        vector<vector<double>> used(query_row+1);

        for(int i=0; i<=query_row; i++){
            vector<double> nleft(i+2);
            for(int j=0; j<left.size(); j++){
                
                double val = min(1.0, left[j]);
                used[i].push_back(val);
                left[j] -= val;

                nleft[j] += left[j]/2;
                nleft[j+1] += left[j]/2;
            }
            left = nleft;
        }

        return used[query_row][query_glass];
    }
};


// 1
// 1 1
// 1 2 1
// 1 3 3 1