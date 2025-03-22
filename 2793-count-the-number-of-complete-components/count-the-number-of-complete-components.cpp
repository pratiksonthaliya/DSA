class Solution {
private:
    vector<int> parent, size;
    int find(int x){
        if(parent[x] == x){
            return x;
        } 
        return parent[x] = find(parent[x]);
    }
    void Union(int a, int b){
        int p_a = find(a);
        int p_b = find(b);

        if(p_a == p_b) return;

        if(size[p_a] > size[p_b]) {
            parent[p_b] = p_a;
            size[p_a] += size[p_b];
        } else {
            parent[p_a] = p_b;
            size[p_b] += size[p_a];
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        size.resize(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }

        unordered_map<int, int> edgeCount;
        for(auto &edge : edges){
            int root = find(edge[0]);
            edgeCount[root]++;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(find(i) == i){ // if node is root
                int nodes = size[i];
                int edges = edgeCount[i];

                if(nodes * (nodes - 1) / 2 == edges){
                    ans++;
                }
            }
        }

        return ans;
    }
};