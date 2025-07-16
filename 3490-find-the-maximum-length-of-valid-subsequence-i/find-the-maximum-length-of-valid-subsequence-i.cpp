class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int oddCt = (nums[0]&1), evenCt = !oddCt, alt = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i]%2 != nums[i-1]%2){
                alt++;
            }

            if(nums[i]&1) oddCt++;
            else evenCt++;
        }

        return max({alt, evenCt, oddCt});
    }
};