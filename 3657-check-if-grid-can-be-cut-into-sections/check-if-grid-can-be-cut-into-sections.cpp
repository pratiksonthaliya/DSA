class Solution {
// private:
//     bool
public:
    bool checkValidCuts(int n, vector<vector<int>>& rects) {
        sort(rects.begin(), rects.end(), [](auto &a, auto &b) {
            if(a[0] == b[0]) return a[2] < b[2];
            return a[0] < b[0];
        });

        int endIdx = 0, ct = 0;
        for(auto &a : rects){
            if(a[0] >= endIdx) {
                ct++;
                if(ct == 3){
                    return true;
                }
            }
            endIdx = max(endIdx, a[2]);
        }

        sort(rects.begin(), rects.end(), [](auto &a, auto &b) {
            if(a[1] == b[1]) return a[3] < b[3];
            return a[1] < b[1];
        });

        endIdx = 0, ct = 0;
        for(auto &a : rects){
            if(a[1] >= endIdx) {
                ct++;
                if(ct == 3){
                    return true;
                }
            }
            endIdx = max(endIdx, a[3]);
        }

        return false;
    }
};