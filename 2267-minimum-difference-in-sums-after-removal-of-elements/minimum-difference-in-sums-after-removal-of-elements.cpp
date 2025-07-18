class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;

        vector<long long> preMinSum(3*n, 0), sufMaxSum(3*n, 0);
        priority_queue<int> mxPQ;
        priority_queue<int, vector<int>, greater<>> mnPQ;

        long long sum1 = 0, sum2 = 0;
        for(int i=0; i<3*n; i++){
            mxPQ.push(nums[i]);
            mnPQ.push(nums[3*n-1-i]);

            sum1 += nums[i];
            sum2 += nums[3*n-1-i];

            while(mxPQ.size() > n){
                sum1 -= mxPQ.top();
                mxPQ.pop();
            }

            while(mnPQ.size() > n){
                sum2 -= mnPQ.top();
                mnPQ.pop();
            }

            preMinSum[i] = sum1;
            sufMaxSum[3*n-1-i] = sum2;
            // cout << sum << " ";
        }

        // for(int i=0; i<3*n; i++){
        //     cout << preMinSum[i] << " ";
        // }
        // cout << endl;

        // for(int i=0; i<3*n; i++){
        //     cout << sufMaxSum[i] << " ";
        // }

        long long ans = LLONG_MAX;
        for(int i=n-1; i<2*n; i++){
            ans = min(ans, preMinSum[i] - sufMaxSum[i+1]);
        }
        return ans;
    }
};