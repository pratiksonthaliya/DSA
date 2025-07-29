class Solution {
public:
    unordered_map<int, vector<int>> adj;
    //vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node){
        while(!adj[node].empty()){
            int nn = adj[node].back();
            adj[node].pop_back();
            dfs(nn);
            //ans.push_back({node, nn});
        }
        path.push_back(node);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int, int> inDegree, outDegree;
        
        for(auto &x : pairs){
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
            outDegree[x[0]]++;
        }
        
        int stNode = -1;
        for(auto entry : outDegree){
            int node = entry.first;
            if(outDegree[node] - inDegree[node] == 1){
                stNode = node;
                break;
            }
        }

        if(stNode == -1) stNode = pairs[0][0];
        
        dfs(stNode);
        // reverse(ans.begin(), ans.end());
        // return ans;

        reverse(path.begin(), path.end());
        vector<vector<int>> res;
        for(int i=1; i<path.size(); i++){
            res.push_back({path[i-1], path[i]});
        }
        return res;
    }
};