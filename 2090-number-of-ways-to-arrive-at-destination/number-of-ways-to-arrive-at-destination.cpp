#define p pair<long long, long long>
const int MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long, vector<p>> adj;
        for(auto &edge : roads){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<p , vector<p>, greater<p>> pq;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        pq.push({0, 0});    
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto nn : adj[node]){
                int nextNode = nn.first;
                int nextDis = nn.second;
                if(dist[nextNode] > dis + nextDis){
                    dist[nextNode] = dis + nextDis;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[node]%MOD; 
                } else if(dist[nextNode] == dis + nextDis){
                    ways[nextNode] = (ways[node] + ways[nextNode]) % MOD; 
                }
            }
        }

        return ways[n-1];
    }
};