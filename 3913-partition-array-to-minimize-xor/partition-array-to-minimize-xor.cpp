class Solution {
private:
    int solve(int idx, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        if(k == 1) {
            int xr = 0;
            for(int i=idx; i<nums.size(); i++){
                xr ^= nums[i];
            }
            return xr;
        }

        int inc = 0, ans = INT_MAX;
        for(int i=idx; i<=nums.size() - k; i++){
            inc ^= nums[i];
            int exc = solve(i+1, k-1, nums, dp);
            ans = min(ans, max(inc, exc));
        }

        return dp[idx][k] = ans;
    }
public:
    int minXor(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (k+1, -1));
        return solve(0, k, nums, dp);
    }
};