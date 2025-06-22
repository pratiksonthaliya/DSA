class Solution {
private:
    int change(int amount, const vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }

public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            
            int amount = i + 1;

            if (ans.empty()) {
                if (numWays[i] == 1) {
                    ans.push_back(amount);
                } else if(numWays[i] != 0) {
                    return {};
                }
            } else {
                int ways = change(amount, ans);

                if (ways == numWays[i]) {
                    continue;
                }

                // Try adding this coin
                vector<int> t = ans;
                t.push_back(amount);
                ways = change(amount, t);

                if (ways == numWays[i]) {
                    ans = t;
                } else {
                    return {};
                }
            }
        }

        return ans;
    }
};
