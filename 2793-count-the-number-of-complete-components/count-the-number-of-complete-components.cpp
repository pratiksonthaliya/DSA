class Solution {
private: 
    void dfs(int node, unordered_map<int, vector<int>> &mp, vector<bool> &vis, int &visCt, int &edgeCt){
        if(vis[node] == 1 || mp.find(node) == mp.end()){
            return;
        }

        vis[node] = 1;
        visCt = visCt + 1;

        for(auto &nn : mp[node]){
            edgeCt = edgeCt + 1;
            if(!vis[nn]){
                dfs(nn, mp, vis, visCt, edgeCt);
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
                int visCt = 0, edgeCt = 0;
                dfs(i, mp, vis, visCt, edgeCt);
                // ct++;

                cout << visCt << " " << edgeCt << endl;

                if(edgeCt/2 == (visCt*(visCt-1))/2){
                    ct++;
                }
            }
        }

        return ct;
    }
};