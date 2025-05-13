class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> mp(26, 0);
        for(char &ch : s) mp[ch - 'a']++;

        for(int i=0; i<t; i++){
            vector<long long> new_mp(26, 0);

            for(int i=0; i<25; i++){
                new_mp[i+1] = mp[i]%MOD;
            }
            new_mp[0] = (new_mp[0]%MOD + mp[25]%MOD)%MOD;
            new_mp[1] = (new_mp[1]%MOD + mp[25]%MOD)%MOD;

            mp = new_mp;
        }

        int ans = 0;
        for(long long val : mp){
            ans = (ans%MOD + val%MOD)%MOD;
        }
        return ans;
    }
};