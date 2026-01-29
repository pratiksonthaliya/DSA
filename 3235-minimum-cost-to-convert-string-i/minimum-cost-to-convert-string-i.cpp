class Solution {
private:
    map<char, vector<pair<char, long long>>> adj;
    
    void dijkstra(char from, vector<vector<long long>> &cos){

        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<>> pq;
        pq.push({0, from});
        cos[from - 'a'][from - 'a'] = 0;

        while(!pq.empty()){
            char ch = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();

            for(auto &x : adj[ch]){
                char nch = x.first;
                long long ncost = cost + x.second;

                if(cos[from - 'a'][nch - 'a'] > ncost){
                    cos[from - 'a'][nch - 'a'] = ncost;
                    pq.push({ncost, nch});
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // make graph
        for(int i=0; i<cost.size(); i++){
            adj[original[i]].push_back({changed[i], 1LL*cost[i]});
        }

        vector<vector<long long>> cos(26, vector<long long>(26, LLONG_MAX));
        for(char ch='a'; ch<='z'; ch++){
            dijkstra(ch, cos);
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(cos[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) return -1;
            ans += cos[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};