class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int minVal = INT_MAX;

        for (int x : basket1) {
            freq[x]++;
            minVal = min(minVal, x);
        }
        for (int x : basket2) {
            freq[x]--;
            minVal = min(minVal, x);
        }

        vector<int> toSwap;
        for (auto [val, count] : freq) {
            if (count % 2 != 0) return -1;
            for (int i = 0; i < abs(count) / 2; ++i)
                toSwap.push_back(val);
        }
        
        int n = toSwap.size() / 2;
        nth_element(toSwap.begin(), toSwap.begin() + n, toSwap.end());

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += min(1LL*toSwap[i], 2LL*minVal);
        }
        return ans;
    }
};