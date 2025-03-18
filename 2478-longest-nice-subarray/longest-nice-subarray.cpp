class Solution {
private: 
    bool isValid(int st, int en, vector<int>& nums){
        for(int i=st; i<=en; i++){
            for(int j=i+1; j<=en; j++){
                if((nums[i] & nums[j]) != 0){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int i=0, j=0;
        while(j < n){
            while(!isValid(i, j, nums)){
                i++;
            } 
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};