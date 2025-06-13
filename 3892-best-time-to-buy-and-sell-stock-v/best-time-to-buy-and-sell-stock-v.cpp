class Solution {
private:
    long long solve(int idx, int state, int cap, vector<int>& prices, vector<vector<vector<long long>>> &dp){

        if(cap == 0){
            return (state == 0 ? 0 : -1e12);
        }

        if(idx >= prices.size()){
            return (state == 0 ? 0 : -1e12);
        }

        if(dp[idx][state][cap] != -1) return dp[idx][state][cap];
        
        long long ans = solve(idx+1, state, cap, prices, dp); // skip

        if(state == 0){
            ans = max(ans, -prices[idx] + solve(idx+1, 1, cap, prices, dp)); //buy
            ans = max(ans, prices[idx] + solve(idx+1, 2, cap, prices, dp)); //sell

        } else if(state == 1){ // prev buy
            ans = max(ans, prices[idx] + solve(idx+1, 0, cap-1, prices, dp)); //sell
        } else if(state == 2){ // prev sell
            ans = max(ans, -prices[idx] + solve(idx+1, 0, cap-1, prices, dp)); //buy
        }

        return dp[idx][state][cap] = ans;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        // state : dp[i][state][cap]

        // state: 0 -> can do anything
        // state: 1 -> did buy prev  => skip or sell
        // state: 2 -> did sell prev => skip or buy

        int n = prices.size();

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (3, vector<long long> (k + 1, -1)));

        return solve(0, 0, k, prices, dp);
    }
};