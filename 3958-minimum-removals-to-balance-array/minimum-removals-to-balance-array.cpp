class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        for(int i=0, j=0; i<n; i++){
            while(j < n && 1LL * nums[i] * k >= nums[j]) j++;

            ans = min(ans, n - (j-i));
        }
        return ans;
    }
};