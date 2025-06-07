class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        int ct = 0, prev_end = INT_MIN;
        for(int i=0; i<n; i++){
            if(prev_end <= arr[i][0]){
                ct++;
                prev_end = max(prev_end, arr[i][1]);
            }
        }
        
        return n - ct;
    }
};