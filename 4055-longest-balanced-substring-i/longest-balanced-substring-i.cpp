class Solution {
private:
    bool isBalanced(map<char, int> &mp){
        int f = (*mp.begin()).second;
        for(auto &x : mp){
            if(x.second != f) return 0;
        }
        return 1;
    }
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 1;
        for(int i=0; i<n; i++){
            map<char, int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;

                if(isBalanced(mp)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};