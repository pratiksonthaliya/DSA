class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preMax(n, 0), postMax(n, 0);

        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], 1LL*nums[i-1]);
            postMax[n-1-i] = max(postMax[n-i], 1LL*nums[n-i]);
        }
        
        long long ans = 0;
        for(int i=1; i<n-1; i++){
            ans = max(ans, (preMax[i] - nums[i]) * 1LL * postMax[i]);
        }

        return ans;
    }
};