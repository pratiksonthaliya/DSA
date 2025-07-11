class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + nums[i];
        }

        int ans = INT_MAX;
        int i=0, j=0;
        while(i <= n && j <= n){
            while(i <= n && j <= n && pre[j] - pre[i] >= target){
                //cout << j << " " << endl;
                ans = min(ans, j - i);
                i++;
            }
            j++;
        }

        // for(int i=0; i<=n; i++){
        //     auto it = lower_bound(pre.begin() + i + 1, pre.end(), pre[i] + target);
        //     if(it != pre.end()){
        //         int idx = it - pre.begin();
        //         ans = min(ans, idx - i);
        //     }
        // }
        return (ans == INT_MAX ? 0 : ans);
    }
};