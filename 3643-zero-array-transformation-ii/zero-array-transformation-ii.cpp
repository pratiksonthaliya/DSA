class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int st = 0, en = queries.size();
        int ans = -1;
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(canFormZeroArray(nums, queries, mid)){
                ans = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }

    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size();

        vector<int> diff(n+1, 0);
        for(int i=0; i<k; i++){
            int st = queries[i][0];
            int en = queries[i][1];
            int val = queries[i][2];

            diff[st] += val;
            diff[en+1] -= val;
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            if(sum < nums[i]){
                return false;
            }
        }

        return true;
    }
};