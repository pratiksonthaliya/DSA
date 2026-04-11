class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &x : mp){
            vector<int> &idxs = x.second;
            for(int i=1; i<idxs.size()-1; i++){
                ans = min(ans, abs(idxs[i]-idxs[i-1]) + abs(idxs[i]-idxs[i+1]) + abs(idxs[i+1]-idxs[i-1]));
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};