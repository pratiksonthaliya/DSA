class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, mx = 0, mn = 0;

        for(int d : differences){
            sum += d;
            mx = max(mx, sum);
            mn = min(mn, sum);
        }

        int ans = (upper - lower) + 1 - (mx - mn);
        if(ans <= 0) return 0;
        return ans;
    }
};