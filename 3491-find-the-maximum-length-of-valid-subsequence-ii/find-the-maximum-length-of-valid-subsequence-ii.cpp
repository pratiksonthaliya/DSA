class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> pos(1001);
        for(int i=0; i<n; i++){
            nums[i] = nums[i]%k;
            pos[nums[i]].push_back(i);
        }

        int ans = 0;
        for(int x=0; x<k; x++){
            for(int y=0; y<k; y++){
                
                vector<int> idxs1 = pos[x];
                vector<int> idxs2 = pos[y];

                int i=0, n=idxs1.size(), j=0, m=idxs2.size(); 
                int idx = -1, ct = 0;
                bool turn = true;

                while(i<n && j<m){
                    if(turn){
                        while(i < n && idxs1[i] <= idx) i++;
                        if(i >= n) break;
                        ct++;
                        idx = idxs1[i];
                        // i++;
                    }
                    else {
                        while(j < m && idxs2[j] <= idx) j++;
                        if(j >= m) break;
                        ct++;
                        idx = idxs2[j];
                        // j++;
                    }
                    turn = !turn;
                }

                ans = max(ans, ct);
            }
        }
        return ans;
    }
};