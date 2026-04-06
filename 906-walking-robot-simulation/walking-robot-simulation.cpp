class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> x_y, y_x;
        for(auto a : obstacles){
            int x = a[0];
            int y = a[1];
            x_y[x].insert(y);
            y_x[y].insert(x);
        }
        
        long long int x = 0, y = 0;
        long long ans = 0;
        int dir = 0;
        
        // N->0, 
        // E->1, 
        // S->2, 
        // W->3
        
        //+1 for right(-1)
        //-1 for left(+1)
        
        for(int i : commands){
            if(i == -1){ //Right
                dir = (dir + 1)%4;
                continue;
            }
            else if(i == -2){ //Left
                dir = (dir - 1 + 4)%4;
                continue;
            }
            
            else if(dir == 0 || dir == 2){ //look for x_y
                long long ny = y + ((dir == 0) ? i : -1*i);
                
                auto it = x_y[x].upper_bound(y);
                if(ny > y && it != x_y[x].end() && *it <= ny && *it > y){
                    ny = (*it) - 1;
                }
                
                // it = x_y[x].lower_bound(y);
                if(ny < y && it != x_y[x].begin() && *(--it) >= ny && *it < y){
                    ny = *(it) + 1;
                }
                
                y = ny;
            } 
            
            else if(dir == 1 || dir == 3){ //look for y_x
                long long nx = x + ((dir == 1) ? i : -1*i);
                
                auto it = y_x[y].upper_bound(x);
                if(nx > x && it != y_x[y].end() && *it <= nx && *it > x){
                    nx = (*it) - 1;
                }
                
                // it = y_x[y].lower_bound(x);
                if(nx < x && it != y_x[y].begin() && *(--it) >= nx && *it < x){
                    nx = *(it) + 1;
                }
                
                x = nx;
            } 
            
            cout << x << " " << y << " " << dir << endl;
            
            ans = max(ans, x*x + y*y);
        }
        
        return ans;
    }
};