class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int val = 0;
            if(nums[i] > 0){
                int d = nums[i]%n;
                val = nums[(i + d)%n];
            } else if(nums[i] < 0){
                int d = abs(nums[i]) % n;
                val = nums[(i - d + n)%n];
            }
            ans[i] = val;
        }
        return ans;
    }
};