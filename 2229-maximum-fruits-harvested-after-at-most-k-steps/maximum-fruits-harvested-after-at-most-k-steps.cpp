class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = 2e5 + 3;
        vector<int> fruit(N, 0);
        for(auto x : fruits){
            fruit[x[0]] = x[1];
        }

        vector<int> pre(N + 1, 0);
        for(int i=0; i<N; i++){
            pre[i+1] = pre[i] + fruit[i];
        }

        int ans = 0;
        for(int dis=k; dis>=0; dis-=2){

            // Forward
            int en = min(N-1, startPos + dis);
            int st = max(0, startPos - (k - dis)/2);
            ans = max(ans, pre[en+1] - pre[st]);

            // Backward
            en = min(N-1, startPos + (k-dis)/2);
            st = max(0, startPos - dis);
            ans = max(ans, pre[en+1] - pre[st]);
        }

        return ans;
    }
};