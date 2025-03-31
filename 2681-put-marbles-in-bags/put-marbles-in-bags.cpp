class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == n || k == 1) return 0;

        vector<long long> values;
        for(int i=0; i<n-1; i++){
            long long sum = weights[i] + weights[i+1];
            values.push_back(sum);
        }

        sort(values.begin(), values.end());

        long long ans = 0;
        for(int i=1; i<k; i++){
            ans += (values[n-i-1] - values[i-1]); 
        }

        return ans;
    }
};