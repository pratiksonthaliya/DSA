class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        for(int i=0; i<n; i++){
            int r = upper_bound(nums.begin(), nums.end(), 1LL * k * nums[i]) - nums.begin();

            ans = min(ans, n - (r-i));
        }
        return ans;
    }
};