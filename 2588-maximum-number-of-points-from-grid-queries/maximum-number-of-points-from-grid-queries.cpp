#define P pair<int, int>
class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<int> ans(k, 0);
        
        vector<P> sortedQueries;
        for(int i=0; i<k; i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>> > pq;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int ct = 0;
        for(auto &q : sortedQueries){
            while(pq.size() > 0 && pq.top().first < q.first){
                auto it = pq.top(); pq.pop();
                
                ct++;

                for(int i=0; i<4; i++){
                    int xx = dx[i] + it.second.first;
                    int yy = dy[i] + it.second.second;

                    if(xx >= 0 && yy >= 0 && xx < n && yy < m && !vis[xx][yy]){
                        pq.push({grid[xx][yy], {xx, yy}});
                        vis[xx][yy] = 1;
                    }
                }
            }

            ans[q.second] = ct;
        }

        return ans;
    }
};