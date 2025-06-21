class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
    
        // [[9]]         -> 1
        // [[9], [4]]    -> 1
        // [[9], [4, 1]], [[9], [4], [1]] -> 2
        // [[9], [4, 1, 3]], [[9], [4], [1], [3]], [[9], [4], [1, 3]], [[9], [4, 1], [3]] -> 4
        // [[9], [4, 1], [3, 7]], [[9], [4, 1, 3], [7]] -> 

        int n = nums.size();
        vector<long long> dp(n+1), pre(n+1, 0);
        dp[0] = pre[0] = 1;

        multiset<int> mp;
        int i=0, j=0;

        while(j < n){
            mp.insert(nums[j]);
            while(*(--mp.end()) - *mp.begin() > k){
                mp.erase(mp.find(nums[i]));
                i++;
            }

            long long val = pre[j] - (i == 0 ? 0 : pre[i-1]);

            dp[j+1] = val%MOD;
            pre[j+1] = pre[j] + dp[j+1];
            j++;
        }

        return dp[n];
    }
};