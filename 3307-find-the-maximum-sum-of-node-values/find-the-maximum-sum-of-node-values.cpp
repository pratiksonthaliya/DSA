class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        int ct = 0, ct2 = 0, diff = INT_MAX;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){

            int val = nums[i], xr = (nums[i]^k);

            diff = min(diff, abs(xr - val));

            if(xr > val) ct++;
            if(xr == val) ct2++;

            ans += max(xr, val);
        }

        if((ct&1) == 1 && ct2 == 0){
            ans = ans - diff;
        }
    
        return ans;
    }
};