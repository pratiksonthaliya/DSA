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

        if(nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());

        long long avg = accumulate(nums.begin(), nums.end(), 0l) / nums.size();

        int k1 = avg - avg%x;
        int k2 = k1 + x;

        int n = nums.size();

        int ans = getAns(nums[n/2], x, nums);
        // int ct2 = getAns(nums[(n+1)/2], x, nums);

        // int ans = min(ct1, ct2);
        return (ans == INT_MAX) ? -1 : ans;
    }
};