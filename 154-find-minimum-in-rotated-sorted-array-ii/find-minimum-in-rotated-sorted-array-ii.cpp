class Solution {
public:
    // TC - O(n - log(n)) and Sc - O(1)
    int search(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[r]){
            return search(nums, mid+1, r);
        }
        if(nums[mid] < nums[r]){
            return search(nums, l, mid);
        }
        return search(nums, l, r-1); //linearly search kro since we dont have enough data
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return search(nums, 0, n-1);
    }
};