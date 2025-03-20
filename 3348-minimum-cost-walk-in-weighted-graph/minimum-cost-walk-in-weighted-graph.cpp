class Solution {
private:
    vector<int> parent;
    vector<int> depth;
    int find(int node){
        if(parent[node] == -1){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void Union(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);

        if(root1 == root2) return;

        if(depth[root1] < depth[root2]){
            swap(root1, root2);
        }

        parent[root2] = root1;
        if(depth[root1] == depth[root2]) depth[root1]++;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        parent.resize(n, -1);
        depth.resize(n, 0);

        vector<int> costs(n, pow(2, 31) - 1);
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }

        for(auto &edge : edges){
            int root = find(edge[0]);
            costs[root] &= edge[2];
        }

        vector<int> ans;
        for(auto &q : queries){
            int st = q[0];
            int en = q[1];

            if(find(st) != find(en)){
                ans.push_back(-1);
            } else {
                int root = find(st);
                ans.push_back(costs[root]);
            }
        }

        return ans;
    }
};