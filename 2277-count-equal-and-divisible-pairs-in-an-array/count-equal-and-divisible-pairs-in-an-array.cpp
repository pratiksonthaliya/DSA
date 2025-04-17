class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; // {val, {idx1, idx2, ...}}
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto x : mp){
            vector<int> &t = x.second;
            int sz = t.size();
            if(sz > 1){
                for(int i=0; i<sz; i++){
                    for(int j=i+1; j<sz; j++){
                        if((t[i]*t[j])%k == 0) ans++;
                    }
                }
            }
        }
        return ans;
    }
};