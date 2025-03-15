class Solution {
private:
    bool isValid(int val, vector<int>& nums, int k){
        int n = nums.size();
        
        int ct = 0;
        for(int i=0; i<n; i++){
            if(nums[i] <= val){
                ct++;
                i++;
            }
        }

        return ct >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int st = *min_element(nums.begin(), nums.end());
        int en = *max_element(nums.begin(), nums.end());

        int ans = en;
        while(st <= en){
            int mid = st + (en - st) / 2;

            if(isValid(mid, nums, k)){
                ans = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};