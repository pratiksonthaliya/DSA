class Solution {
private:
    int mx_or;
    int solve(int i, int curr_or, vector<int>& nums){
        // if(curr_or == mx_or) return 1;

        if(i == nums.size()){
            return curr_or == mx_or;
        }

        int skip = solve(i+1, curr_or, nums);
        int pick = solve(i+1, curr_or | nums[i], nums);
        
        return pick + skip;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        mx_or = 0;
        for(int &num : nums) mx_or |= num;

        cout << mx_or << endl;

        return solve(0, 0, nums);
    }
};