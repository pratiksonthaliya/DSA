class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;

        int i = 1, j = 1;
        while(i<n-1 && j<n){
            int j = i+1;
            while(j < n && nums[i] == nums[j]) j++;

            if(j < n) {
                if(nums[i-1] > nums[i] && nums[j] > nums[i]) ans++;
                if(nums[i-1] < nums[i] && nums[j] < nums[i]) ans++;
            }
            i=j;
        }

        return ans;
    }
};