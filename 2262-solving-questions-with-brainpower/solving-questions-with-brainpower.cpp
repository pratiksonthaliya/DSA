class Solution {
private:
    long long solve(int idx, vector<vector<int>>& q, vector<long long>& dp){
        if(idx >= q.size()) return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }

        long long pick = q[idx][0] + solve(idx + 1 + q[idx][1], q, dp);
        long long skip = solve(idx + 1, q, dp);
        return dp[idx] = max(pick, skip);
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, -1);
        return solve(0, q, dp);
    }
};