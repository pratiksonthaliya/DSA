class Solution {
private:
    int calDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numWithOriginalIdx;
        for (int i = 0; i < n; ++i) {
            numWithOriginalIdx.push_back({nums[i], i});
        }

        sort(numWithOriginalIdx.begin(), numWithOriginalIdx.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = calDigitSum(a.first);
            int sumB = calDigitSum(b.first);
            if (sumA != sumB) return sumA < sumB;
            return a.first < b.first;
        });

        int swaps = 0;
        vector<bool> vis(n, 0);

        for(int i=0; i<n; i++){
            if(vis[i]) continue;

            int cycleLen = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                j = numWithOriginalIdx[j].second;
                cycleLen++;
            }

            swaps += (cycleLen - 1);
        }

        return swaps;
    }
};
