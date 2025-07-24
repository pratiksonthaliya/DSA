class Solution {
private:
    vector<vector<int>> tree;
    vector<int> subXor;
    vector<int> inTime, outTime;
    int timer = 0;
    int totalXor = 0;

    void dfs(int node, int parent, vector<int>& nums) {
        inTime[node] = timer++;
        subXor[node] = nums[node];

        for (int nei : tree[node]) {
            if (nei == parent) continue;
            dfs(nei, node, nums);
            subXor[node] ^= subXor[nei];
        }

        outTime[node] = timer++;
    }

    bool isDescendant(int u, int v) {
        // return true if u is in the subtree of v
        return inTime[v] < inTime[u] && outTime[u] < outTime[v];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        subXor.resize(n);
        inTime.resize(n);
        outTime.resize(n);

        // Do DFS from root 0
        dfs(0, -1, nums);

        totalXor = subXor[0];
        int minScore = INT_MAX;

        // Try all pairs of nodes (as edge removal targets)
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int a, b, c;

                if (isDescendant(u, v)) {
                    // u is in subtree of v
                    a = subXor[u];
                    b = subXor[v] ^ subXor[u];
                    c = totalXor ^ subXor[v];
                } else if (isDescendant(v, u)) {
                    // v is in subtree of u
                    a = subXor[v];
                    b = subXor[u] ^ subXor[v];
                    c = totalXor ^ subXor[u];
                } else {
                    // u and v are in different subtrees
                    a = subXor[u];
                    b = subXor[v];
                    c = totalXor ^ subXor[u] ^ subXor[v];
                }

                int maxX = max({a, b, c});
                int minX = min({a, b, c});
                minScore = min(minScore, maxX - minX);
            }
        }

        return minScore;
    }
};
