class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--){
            while(nums[i] > 0){
                ans.push_back(nums[i]%10);
                nums[i]/=10;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};