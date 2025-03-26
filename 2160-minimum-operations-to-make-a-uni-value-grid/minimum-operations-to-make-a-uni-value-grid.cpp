class Solution {
private:
    int getAns(int k, int x, vector<int>& nums){
        int ct = 0;
        for(int &val : nums){
            if(val != k){
                if(abs(val - k) % x != 0) {
                    ct = INT_MAX;
                    break;
                }
                ct += abs(val - k)/x;
            }
        }
        return ct;
    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto &v : grid){
            for(int &num : v){
                nums.push_back(num);
            }
        }    

        int n = nums.size();
        if(n == 1) return 0;

        sort(nums.begin(), nums.end());
        int ans = getAns(nums[n/2], x, nums);
        return (ans == INT_MAX) ? -1 : ans;
    }
};