class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(m == 1){
            // if(n == 2) return grid[0][0] == grid[0][1];
            long long sum = 0;
            vector<long long> pre(n, 0), suf(n, 0);
            for(int i=0; i<n; i++){
                sum += grid[0][i];
                pre[i] = sum;
            }

            sum = 0;
            for(int i=n-1; i>=0; i--){
                sum += grid[0][i];
                suf[i] = sum;
            }

            for(int i=0; i<n; i++){
                if(i>0 && pre[i-1] == suf[i]) return true;
                if(i>0 && i<n-1 && pre[i-1] == suf[i+1]) return true;
            }

            for(int i=1; i<n-1; i++){
                if(pre[i] - pre[0] == suf[i+1]) return true;
                if(suf[i] - suf[n-1] == pre[i-1]) return true;
            }

            return false;
        }

        if(n == 1){
            // if(m == 2) return grid[0][0] == grid[1][0];
            long long sum = 0;
            vector<long long> pre(m, 0), suf(m, 0);
            for(int i=0; i<m; i++){
                sum += grid[i][0];
                pre[i] = sum;
            }

            sum = 0;
            for(int i=m-1; i>=0; i--){
                sum += grid[i][0];
                suf[i] = sum;
            }

            for(int i=0; i<m; i++){
                if(i>0 && pre[i-1] == suf[i]) return true;
                if(i>0 && i<m-1 && pre[i-1] == suf[i+1]) return true;
            }

            for(int i=1; i<m-1; i++){
                if(pre[i] - pre[0] == suf[i+1]) return true;
                if(suf[i] - suf[m-1] == pre[i-1]) return true;
            }

            return false;
        }
        
        long long totalSum = 0;
        unordered_map<int, int> top, bottom, left, right;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                totalSum += val;

                if(i > 0 && i < m-1) bottom[val]++;
                if(j > 0 && j < n-1) right[val]++;

                if((i == 0 || i == m-1) && (j == 0 || j == n-1)){
                    bottom[val]++;
                    right[val]++;
                }

                // if(j == 0 || j == n-1){
                //     bottom[val]++;
                // }
                // if(i == 0 || i == m-1){
                //     right[val]++;    
                // }
            }
        }
        
        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                topSum += grid[i][j];

                // if(j == 0 || j == n-1){
                //     top[grid[i][j]]++;
                //     bottom[grid[i][j]]--;
                //     if(bottom[grid[i][j]] <= 0) bottom.erase(grid[i][j]);    
                // }
                
                if(i > 0 || (i == 0 && (j == 0 || j == n-1))){
                    top[grid[i][j]]++;
                    bottom[grid[i][j]]--;
                    if(bottom[grid[i][j]] <= 0) bottom.erase(grid[i][j]);    
                }
            }
            
            long long bottomSum = totalSum - topSum;
            if (topSum == bottomSum) return true;

            long long diff = abs(topSum - bottomSum);
            if (topSum > bottomSum) {
                if(top.find(diff) != top.end()){
                    return true;
                }
            } else {
                if(bottom.find(diff) != bottom.end()){
                    return true;
                }
            }
        }

        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                leftSum += grid[i][j];

                // if(i == 0 || i == m-1){
                //     left[grid[i][j]]++;
                //     right[grid[i][j]]--;
                //     if(right[grid[i][j]] <= 0) right.erase(grid[i][j]); 
                // }
                
                if(j > 0 || (j == 0 && (i == 0 || i == m-1))){
                    left[grid[i][j]]++;
                    right[grid[i][j]]--;
                    if(right[grid[i][j]] <= 0) right.erase(grid[i][j]); 
                }
            }
            
            long long rightSum = totalSum - leftSum;
            if (leftSum == rightSum) return true;

            long long diff = abs(leftSum - rightSum);
            if (leftSum > rightSum) {
                if(left.find(diff) != left.end()){
                    return true;
                }
            } else {
                if(right.find(diff) != right.end()){
                    return true;
                }
            }
        }

        return false;
    }
};