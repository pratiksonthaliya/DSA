class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int val = 0;
        for(int &num : nums) val |= num;
        return (val << (nums.size() - 1));
    }
};