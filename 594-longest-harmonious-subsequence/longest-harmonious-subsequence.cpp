class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int ans = 0;
        for(auto x : mp){
            if(mp.find(x.first + 1) != mp.end()){
                ans = max(ans, mp[x.first] + mp[x.first + 1]);
            }
        }
        return ans;
    }
};