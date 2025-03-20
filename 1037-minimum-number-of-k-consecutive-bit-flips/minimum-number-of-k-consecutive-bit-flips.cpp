class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flips(n+1, 0);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i > 0) flips[i] += flips[i-1];
            
            if(i > n-k){ // check those idx where we can't apply operations now
                if((flips[i] + nums[i])%2 == 0){
                    return -1;
                }
                continue;
            }

            if((nums[i] + flips[i])%2 == 0){
                ans++;
                if(i+k > n) return -1;
                flips[i] += 1;
                flips[i+k] -= 1;
            }
        }

        return ans;
    }
};