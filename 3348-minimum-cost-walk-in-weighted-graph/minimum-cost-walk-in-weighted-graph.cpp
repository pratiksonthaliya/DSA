class Solution {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y) {
            return;
        }

        parent[p_x] = p_y;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }

        vector<int> cost(n, -1);
        for(auto &edge : edges){
            int par = find(edge[0]);
            cost[par] &= edge[2];
        }

        vector<int> ans;
        for(auto &q : query){
            int p_x = find(q[0]);
            int p_y = find(q[1]);

            if(p_x != p_y){
                ans.push_back(-1);
            } else {
                ans.push_back(cost[p_x]);
            }
        }

        return ans;
    }
};