class Solution {
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pows(n, 1);
        for(int i = 1 ; i < n ; i++){ 
            pows[i] = (pows[i - 1] * 2) % mod;
        }

        int i = 0, j = n-1, ans = 0;
        while(i <= j){
            if(nums[i] + nums[j] > target){
                j--;
            } else {
                ans = (ans + pows[j-i])%mod;
                i++;
            }
        }
        return ans;
    }
};