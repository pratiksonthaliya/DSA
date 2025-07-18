class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;

        vector<long long> preMinSum(3*n, 0);
        priority_queue<int> mxPQ;
        long long sum1 = 0, sum2 = 0;
        for(int i=0; i<3*n; i++){
            mxPQ.push(nums[i]);
            sum1 += nums[i];

            while(mxPQ.size() > n){
                sum1 -= mxPQ.top();
                mxPQ.pop();
            }
            preMinSum[i] = sum1;
        }

        priority_queue<int, vector<int>, greater<>> mnPQ;
        vector<long long> sufMaxSum(3*n, 0);
        for(int i=3*n-1; i>=0; i--){
            mnPQ.push(nums[i]);
            sum2 += nums[i];

            while(mnPQ.size() > n){
                sum2 -= mnPQ.top();
                mnPQ.pop();
            }
            sufMaxSum[i] = sum2;
        }

        long long ans = LLONG_MAX;
        for(int i=n-1; i<2*n; i++){
            ans = min(ans, preMinSum[i] - sufMaxSum[i+1]);
        }
        return ans;
    }
};