class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> res;
    vector<vector<int>> ans;

    void dfs(int node){
        while(!adj[node].empty()){
            int nn = adj[node].back();
            adj[node].pop_back();
            dfs(nn);
            ans.push_back({node, nn});
        }
        //res.push_back(node);
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
        reverse(ans.begin(), ans.end());
        // return ans;

        // vector<vector<int>> ans;
        // for(int i=0; i<res.size(); i++){
        //     ans.push_back({res[i-1], res[i]});
        // }
        return ans;
    }
};