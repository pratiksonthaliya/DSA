class Solution {
public:
    int findMin(vector<int>& nums) {
        //Tc - O(log(n)) and SC - O(1)
        int n = nums.size();
        if(nums[0] <= nums[n-1]) return nums[0];

        int st = 0;
        int en = n-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] <= nums[(mid-1+n)%n]){ // visualize it 
                return nums[mid];
            }
            else if(nums[mid]>=nums[0]){
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        return 0;
    }
};