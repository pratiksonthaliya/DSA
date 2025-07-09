class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> graph(n);
        for(auto x : edges){
            graph[x[0]].push_back({x[1], x[2], x[3]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {time, node}
        pq.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while(!pq.empty()){
            int time = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();

            if(node == n-1) return time;
            if(dist[node] < time) continue;

            for(auto x : graph[node]){
                int nnode = x[0], st_t = x[1], en_t = x[2];
                
                if(time > en_t) continue;

                int departTime = max(st_t, time) + 1;
                if(dist[nnode] > departTime){
                    dist[nnode] = departTime;
                    pq.push({dist[nnode], nnode});
                }
            }
        }

        return -1;
    }
};