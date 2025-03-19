class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 3;
        
        int ct = 0;
        for(int i=0; i<=n-k; i++){
            if(nums[i] == 1) continue;
            for(int j=i; j<i+k; j++){
                nums[j] = 1 - nums[j];
            }
            ct++;
        }

        for(int i=0; i<n; i++){
            // cout << nums[i] << " ";
            if(nums[i] == 0) return -1;
        }
        return ct;
    }
};