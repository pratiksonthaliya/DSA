class Solution {
private:
    bool isCycle(int node, int par, int &len, vector<bool>& vis, vector<vector<int>> &graph){
        vis[node] = 1;
        len++;

        bool hasCycle = false;
        for(int &nn : graph[node]){
            if(!vis[nn]){
                hasCycle |= isCycle(nn, node, len, vis, graph);
            } else if(par != -1 && nn != par){
                hasCycle = true;
            }
        }

        return hasCycle;
    }
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<pair<bool, long long>> lens; // cycle, len

        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){

                int len = 0;
                // dfs(i, len, vis, graph);

                vector<bool> vis2(n, 0);
                bool hasCycle = isCycle(i, -1, len, vis, graph);

                if(len > 1){
                    lens.push_back({hasCycle, len});
                }
            }
        }

        sort(lens.rbegin(), lens.rend());

        long long ans = 0;
        int en = n;
        for(auto &[isCycle, len] : lens){
            int st = en - len + 1;

            vector<long long> odd, even;
            for(int i=st; i<=en; i++){
                if(i&1) odd.push_back(i);
                else even.push_back(i);
            }

            for(int i=1; i<odd.size(); i++){
                ans = (ans + odd[i]*odd[i-1]);
            }

            for(int i=1; i<even.size(); i++){
                ans = (ans + even[i]*even[i-1]);
            }

            ans = ans + odd[odd.size()-1]*even[even.size()-1];
            if(isCycle) ans = ans + even[0]*odd[0];

            en = st - 1;
        }

        return ans;
    }
};