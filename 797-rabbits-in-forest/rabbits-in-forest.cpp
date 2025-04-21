class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(int ct : answers) mp[ct]++;

        int ans = 0;
        for(auto x : mp){
            int a = x.second;
            int grpSize = x.first + 1;

            int rem = a%grpSize;

            ans += (a - rem);
            if(a%grpSize != 0) ans += grpSize;
        }

        return ans;
    }
};