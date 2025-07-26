class Solution {
private:
    int tot_xor;
    int timer = 0;
    vector<int> subTreeXor;
    vector<int> inTime, outTime;

    int dfs(int node, int par, vector<int>& nums, vector<vector<int>>& graph){
        inTime[node] = timer;
        timer++;

        int xr = nums[node];
        for(int &nnode : graph[node]){
            if(nnode == par) continue;
            timer++;
            xr ^= dfs(nnode, node, nums, graph);
        }

        outTime[node] = timer;
        timer++;
        
        return subTreeXor[node] = xr;
    }

    bool isDescendant(int u, int v) {
        // return true if u is in the subtree of v
        return inTime[v] < inTime[u] && outTime[u] < outTime[v];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int N = nums.size();
        // Make graph
        vector<vector<int>> graph(N);
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // Find subtreeXor and totalXor
        subTreeXor.assign(N, 0);
        inTime.assign(N, 0);
        outTime.assign(N, 0);
        tot_xor = dfs(0, -1, nums, graph);

        int minScore = INT_MAX;
        for (int u = 1; u < N; ++u) {
            for (int v = u + 1; v < N; ++v) {
                
                int a = 0, b = 0, c = 0;

                if(isDescendant(u, v)){
                    // u is in subtree of v
                    a = subTreeXor[u];
                    b = subTreeXor[v] ^ subTreeXor[u];
                    c = tot_xor ^ subTreeXor[v];
                } else if(isDescendant(v, u)){
                    // v is in subtree of u
                    a = subTreeXor[v];
                    b = subTreeXor[u] ^ subTreeXor[v];
                    c = tot_xor ^ subTreeXor[u];
                } else {
                    a = subTreeXor[u];
                    b = subTreeXor[v];
                    c = tot_xor ^ subTreeXor[v] ^ subTreeXor[u];
                }

                int maxX = max({a, b, c}), minX = min({a, b, c});
                minScore = min(minScore, maxX - minX);
            }
        }

        return minScore;
    }
};