class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int i=0, j=0, n = nums.size();
        int ans = 0, ctz = 0;

        while(j < n){
            if(nums[j] == 0) ctz++;

            while(ctz > 1){
                if(nums[i] == 0) ctz--;
                i++;
            }

            ans = max(ans, j-i);
            j++;
        }

        return ans;
    }
};