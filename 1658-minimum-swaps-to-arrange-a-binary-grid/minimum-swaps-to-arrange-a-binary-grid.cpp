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
            if(arr[i] >= (n-1-i)) continue;

            int k = (n-1 - i);
            int mx_i = n-1, mx = arr[i];

            for(int j=i+1; j<n; j++){
                if(arr[j] >= k){
                    mx_i = j;
                    break;
                }
            }

            for(int j=mx_i; j>i; j--){
                swap(arr[j], arr[j-1]);
                op++;
            }
        }

        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }

        for(int i=0; i<n; i++){
            int k = (n-1 - i);
            if(arr[i] < k) return -1;
        }

        return op;

        // sort(arr.rbegin(), arr.rend());

        // for(int i=0; i<n; i++){
        //     cout << arr[i][0] << " ";
        // }

        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     int k = (n-1 - i);
        //     if(arr[i][0] < k) return -1;
        //     ans += abs(i + arr[i][1]);
        // }
        // return ans;
    }
};