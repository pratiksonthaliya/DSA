class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> seen(128);
        for(int i=n-1; i>=0; i--){
            if(seen[nums[i]] == true){
                return (i + 3) / 3;
            }
            seen[nums[i]] = true;
        }

        return 0;
    }
};