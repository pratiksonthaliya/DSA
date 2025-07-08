class Solution {
private:
    vector<vector<int>> dp;

    int solve(int idx, int k, int prev_end, vector<vector<int>>& events){
        if(idx == events.size() || k == 0){
            return 0;
        }

        if(prev_end >= events[idx][0]){
            return solve(idx + 1, k, prev_end, events);;
        }

        if(dp[k][idx] != -1) return dp[k][idx];

        return dp[k][idx] = max(
            solve(idx + 1, k, prev_end, events), 
            events[idx][2] + solve(idx + 1, k-1, events[idx][1], events)
        );
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // sort(events.begin(), events.end(), [](auto &a, auto &b){
        //     if(a[1] == b[1]) return a[0] < b[0];
        //     return a[1] < b[1];
        // });

        sort(events.begin(), events.end());

        dp.resize(k+1, vector<int> (events.size()+1, -1));

        return solve(0, k, 0, events);
    }   
};