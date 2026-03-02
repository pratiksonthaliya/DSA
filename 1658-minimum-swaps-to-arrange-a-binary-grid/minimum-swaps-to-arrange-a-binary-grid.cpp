class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> arr;
        for(int i=0; i<n; i++){
            int j = m-1;
            while(j >= 0 && grid[i][j] == 0)j--;
            arr.push_back(m-1 - j);
        }

        int op = 0;
        for(int i=0; i<n; i++){
            int val = (n-1 - i);
            if(arr[i] >= val) continue;
            
            int mx_i = -1;
            for(int j=i+1; j<n; j++){
                if(arr[j] >= val){
                    mx_i = j;
                    break;
                }
            }

            if(mx_i == -1) return -1;

            for(int j=mx_i; j>i; j--){
                swap(arr[j], arr[j-1]);
                op++;
            }
        }

        return op;
    }
};