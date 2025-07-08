class Solution {
private:
    vector<vector<int>> dp;
    int findNextIdx(int val, vector<vector<int>>& events){

        int st = 0, en = events.size() - 1, idx = en + 1;
        while(st <= en){

            int mid = st + (en - st)/2;
            if(events[mid][0] > val){
                idx = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return idx;
    }
    int solve(int idx, int k, vector<vector<int>>& events){
        if(idx == events.size() || k == 0){
            return 0;
        }

        if(dp[k][idx] != -1) return dp[k][idx];

        int next_idx = findNextIdx(events[idx][1], events);

        // // skip
        // int skip = solve(idx + 1, k, prev_end, events);

        // //pick
        // int pick = INT_MIN;
        // if(prev_end < events[idx][0] && k > 0){
        //     pick = events[idx][2] + solve(next_idx, k-1, events[idx][1], events);
        // }

        return dp[k][idx] = max(
            solve(idx + 1, k, events), 
            events[idx][2] + solve(next_idx, k-1, events)
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

        return solve(0, k, events);
    }   
};