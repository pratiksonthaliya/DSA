class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1;
        while(st <= en){
            int mid = st + (en - st)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] >= nums[0]){
                if(nums[0] <= target && nums[mid] >= target){
                    en = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if(nums[0] > target && nums[mid] < target){
                    st = mid + 1;
                } else {
                    en = mid - 1;
                }
            }
        }   
        return -1;
    }
};