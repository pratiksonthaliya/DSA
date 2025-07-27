class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        for(int i=1; i<n-1; i++){
            int j = i+1;
            while(j < n && nums[i] == nums[j]) j++;

            if(j < n) {
                if(nums[i-1] > nums[i] && nums[j] > nums[i]) ans++;
                if(nums[i-1] < nums[i] && nums[j] < nums[i]) ans++;
            }
        }

        return ans;
    }
};