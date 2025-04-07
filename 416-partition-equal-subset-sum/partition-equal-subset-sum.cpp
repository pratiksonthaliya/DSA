class Solution {
private:
    bool canPartitionHelper(int i, long long tar, vector<int> &nums, vector<vector<int>> &dp){
        if(tar == 0) return true;

        if(i >= nums.size() || tar < 0) return false;

        if(dp[i][tar] != -1) return dp[i][tar];

        return dp[i][tar] = canPartitionHelper(i+1, tar - nums[i], nums, dp) || canPartitionHelper(i+1, tar, nums, dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        if((sum & 1) == 1) return false;

        vector<vector<int>> dp(n+1, vector<int> (sum/2 + 1, -1));
        return canPartitionHelper(0, sum/2, nums, dp);
    }
};