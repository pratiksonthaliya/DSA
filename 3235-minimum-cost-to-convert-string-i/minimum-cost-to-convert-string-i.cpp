class Solution {
private:
    map<char, vector<pair<char, long long>>> adj;
    
    void dfs(char from, char to, long long cost, vector<vector<long long>> &cos){
        cos[from - 'a'][to - 'a'] = cost;

        for(auto &x : adj[to]){
            char nch = x.first;
            long long ncost = cost + x.second;

            if(cos[from - 'a'][nch - 'a'] > ncost){
                dfs(from, nch, ncost, cos);
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
            dfs(ch, ch, 0, cos);
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(cos[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) return -1;
            ans += cos[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};