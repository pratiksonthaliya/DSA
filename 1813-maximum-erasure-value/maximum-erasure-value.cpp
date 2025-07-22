class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // vector<long long> pre(n+1, 0);
        // for(int i=0; i<n; i++){
        //     pre[i+1] = pre[i] + nums[i];
        // }

        int i=0, j=0;
        long long ans = 0, sum = 0;
        unordered_set<int> st;
        while(i<n && j<n){
            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            st.insert(nums[j]);
            sum += nums[j];
            ans = max(ans, sum);
            // ans = max(ans, pre[j+1] - pre[i]);
            j++;
        }
        return ans;
    }
};