class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preMax(n, 0), postMax(n, 0);

        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], 1LL*nums[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            postMax[i] = max(postMax[i+1], 1LL*nums[i+1]);
        }
        
        long long ans = 0;
        for(int i=1; i<n-1; i++){
            ans = max(ans, (preMax[i] - nums[i]) * 1LL * postMax[i]);
        }

        return ans;
    }
};