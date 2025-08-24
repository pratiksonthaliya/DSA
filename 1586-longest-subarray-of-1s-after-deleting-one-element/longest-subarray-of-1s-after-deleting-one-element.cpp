class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n, 0), suf(n, 0);

        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == 1)
                pre[i] = pre[i-1] + 1;
        }

        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] == 1)
                suf[i] = suf[i+1] + 1;
        }

        // int ans = max(pre[n-2], suf[1]);
        int ans = 0;
        for(int i=0; i<n; i++){
            int val = (i-1 >= 0 ? pre[i-1] : 0) + (i+1 < n ? suf[i+1] : 0);
            ans = max(ans, val);
        }
        return ans;
    }
};