class Solution {
private:
    int sum = 0;
    void findSubsets(int idx, vector<int>& nums, vector<int> &t, vector<bool> &vis){
        if(!t.empty()){
            int xr = 0;
            for(int i : t) xr ^= i;
            sum += xr;
            // cout << xr << " ";
        }

        for(int i=idx; i<nums.size(); i++){
            if(!vis[i]){
                t.push_back(nums[i]);
                vis[i] = 1;
                findSubsets(i+1, nums, t, vis);
                t.pop_back();
                vis[i] = 0;
            }
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> t;
        vector<bool> vis(nums.size(), 0);
        findSubsets(0, nums, t, vis);
        return sum;
    }
};