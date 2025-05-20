class Solution {
private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> portals;
        unordered_set<char> usedPortals;  
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z') {
                    portals[c].push_back({i, j});
                }
            }
        }

        deque<vector<int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));  
        
        dq.push_front({0, 0, 0});
        dist[0][0] = 0;
        
        while (!dq.empty()) {
            auto current = dq.front();
            dq.pop_front();
            
            int steps = current[0], x = current[1], y = current[2];
            
            if (x == m - 1 && y == n - 1) {
                return steps;
            }

            if(steps > dist[x][y]) continue;

            char ch = matrix[x][y];
            if (ch >= 'A' && ch <= 'Z' && usedPortals.find(ch) == usedPortals.end()) {
                for (auto& portal : portals[ch]) {
                    int nx = portal.first, ny = portal.second;
                    if (dist[nx][ny] > steps) {
                        dist[nx][ny] = steps;  
                        dq.push_front({steps, nx, ny});
                    }
                }
                usedPortals.insert(ch);  
            }

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] != '#') {
                    if (dist[nx][ny] > steps + 1) {
                        dist[nx][ny] = steps + 1;
                        dq.push_back({steps + 1, nx, ny});
                    }
                }
            }
        }

        return -1;  
    }
};