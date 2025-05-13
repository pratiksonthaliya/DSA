class Solution {
private:
    void dfs(int node, int &len, vector<bool>& vis, vector<vector<int>> &graph){
        vis[node] = 1;
        len++;

        for(int nn : graph[node]){
            if(!vis[nn]){
                dfs(nn, len, vis, graph);
            }
        }
    }

    bool isCycle(int node, int par, vector<bool>& vis, vector<vector<int>> &graph){
        vis[node] = 1;

        for(int nn : graph[node]){
            if(!vis[nn]){
                return isCycle(nn, node, vis, graph);
            } else if(par != -1 && nn != par){
                return true;
            }
        }

        return false;
    }
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<long long> cycleLen, normalLen;

        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){

                int len = 0;
                dfs(i, len, vis, graph);

                vector<bool> vis2(n, 0);
                bool hasCycle = isCycle(i, -1, vis2, graph);

                if(len > 1){
                    if(hasCycle){
                        cycleLen.push_back(len);
                    } else {
                        normalLen.push_back(len);
                    }
                }

                // if(len > 1) cout << hasCycle << " " << len << endl;
            }
        }

        sort(normalLen.rbegin(), normalLen.rend());
        sort(cycleLen.rbegin(), cycleLen.rend());

        long long ans = 0;
        int en = n;
        for(int len : cycleLen){
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
            ans = ans + even[0]*odd[0];

            en = st - 1;
        }

        for(int len : normalLen){
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
            // ans = ans + even[0]*odd[odd.size()-1];

            en = st - 1;
        }

        // for(int x : normalLen){
        //     cout << x << " ";
        // }
        // cout << endl << endl;;

        // for(int x : cycleLen){
        //     cout << x << " ";
        // }

        return ans;
    }
};