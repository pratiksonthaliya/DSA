class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, set<int>> val_idx;
        for(int i=0; i<n; i++){
            val_idx[nums[i]].insert(i);
        }

        vector<int> ans(queries.size(), -1);
        for(int i=0; i<queries.size(); i++){

            int idx = queries[i];
            int val = nums[queries[i]];
            set<int>& idxs = val_idx[val];
            if(idxs.size() > 1){

                int dis = INT_MAX;
                if(val_idx[val].find(idx) != val_idx[val].begin()){
                    int j = *(--val_idx[val].find(idx));
                    int k = abs(idx - j);
                    dis = min(dis, min(k, n - k));
                } else {
                    int j = *(--val_idx[val].end());
                    int k = abs(idx - j);
                    dis = min(dis, min(k, n - k));
                }

                if(val_idx[val].upper_bound(idx) != val_idx[val].end()){
                    int j = *val_idx[val].upper_bound(idx);
                    int k = abs(idx - j);
                    dis = min(dis, min(k, n - k));
                } else {
                    int j = *(val_idx[val].begin());
                    int k = abs(idx - j);
                    dis = min(dis, min(k, n - k));
                }

                if(dis != INT_MAX){
                    ans[i] = dis;
                }
            }
        }
        return ans;
    }
};