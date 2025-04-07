class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        if((sum & 1) == 1) return false;

        int tar = sum/2;
        vector<vector<int>> dp(n+1, vector<int> (tar + 1, 0));
        dp[n][0] = 1;

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=tar; j++){
                dp[i][j] = dp[i+1][j];
                if(j - nums[i] >= 0){
                    dp[i][j] |= dp[i+1][j - nums[i]];
                } 
            }
        }

        return dp[0][tar];
    }
};