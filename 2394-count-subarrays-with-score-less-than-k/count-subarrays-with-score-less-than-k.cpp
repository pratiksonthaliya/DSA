class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;

        int i=0, j=0, n = nums.size();
        long long sum = 0;

        while(i < n && j < n){
            sum += nums[j];

            while(sum * (j-i+1) >= k){
                sum -= nums[i];
                i++;
            }

            ans += (j-i+1);
            j++;
        }

        return ans;
    }
};