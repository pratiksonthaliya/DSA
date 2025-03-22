class Solution {
private: 
    void dfs(int node, unordered_map<int, vector<int>> &mp, vector<bool> &vis, int &nodeCt, int &edgeCt){
        if(vis[node] == 1 || mp.find(node) == mp.end()){
            return;
        }

        vis[node] = 1;
        nodeCt = nodeCt + 1;
        edgeCt = edgeCt + mp[node].size();

        for(auto &nn : mp[node]){
            if(!vis[nn]){
                dfs(nn, mp, vis, nodeCt, edgeCt);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        int ct = 0;
        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++){
            if(mp.find(i) == mp.end()){
                ct++;
            }
            else if(!vis[i]){
                int nodeCt = 0, edgeCt = 0;
                dfs(i, mp, vis, nodeCt, edgeCt);

                if(edgeCt/2 == (nodeCt*(nodeCt-1))/2){
                    ct++;
                }
            }
        }

        return ct;
    }
};