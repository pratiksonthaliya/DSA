class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        int ct = 0, diff = INT_MAX;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){

            int val = nums[i], xr = (nums[i]^k);
            
            if(xr > val) ct++;
            
            diff = min(diff, abs(xr - val));
            ans += max(xr, val);
        }

        if((ct&1) == 1){
            ans = ans - diff;
        }
    
        return ans;
    }
};