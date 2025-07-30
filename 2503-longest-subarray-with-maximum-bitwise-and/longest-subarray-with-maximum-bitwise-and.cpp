class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx_and = *max_element(nums.begin(), nums.end());

        int ans = 1, len = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == mx_and) len++;
            else len = 0;
            ans = max(ans, len);
        }
        return ans;
    }
};