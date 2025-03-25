class Solution {
private:
    bool check(int st, int en, vector<vector<int>>& rects) {
        sort(rects.begin(), rects.end(), [st, en](auto &a, auto &b) {
            if(a[st] == b[st]) return a[en] < b[en];
            return a[st] < b[st];
        });

        int endIdx = 0, ct = 0;
        for(auto &a : rects){
            if(a[st] >= endIdx) {
                ct++;
                if(ct == 3){
                    return true;
                }
            }
            endIdx = max(endIdx, a[en]);
        }

        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rects) {
        return check(0, 2, rects) || check(1, 3, rects);
    }
};