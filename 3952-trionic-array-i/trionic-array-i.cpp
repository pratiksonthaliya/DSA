class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1, i = 0, n = nums.size();

        while(i+1 < n && nums[i+1] > nums[i]) i++;

        if(i+1 == n) return false;
        else p = i;

        while(i+1 < n && nums[i+1] < nums[i]) i++;
        if(i+1 == n) return false;
        else q = i;

        while(i+1 < n && nums[i+1] > nums[i]) i++;

        if(i+1 == n && p > 0 && p < q && q < n-1) return true;
        else return false;
    }
};