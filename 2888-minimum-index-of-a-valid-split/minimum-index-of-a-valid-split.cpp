class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int maxVal = -1, maxCt = 0;
        for(int i=0; i<n; i++){
            if(maxCt == 0){
                maxVal = nums[i];
                maxCt = 1;
            } else if(nums[i] == maxVal){
                maxCt++;
            } else {
                maxCt--;
            }
        }

        maxCt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maxVal){
                maxCt++;
            }
        }

        int ct = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maxVal){
                ct++;
                if(2 * ct > (i + 1) && 2 * (maxCt - ct) > n - (i + 1)){
                    return i;
                }
            }
        }

        return -1;
    }
};