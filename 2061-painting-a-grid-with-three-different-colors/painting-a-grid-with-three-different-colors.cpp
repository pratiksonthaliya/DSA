class Solution {
private:
    static constexpr int mod = 1000000007;
    unordered_set<string> prevStates;
    void getColumnStates(int i, int m, string s){
        if(i == m){
            prevStates.insert(s);
            return;
        }

        if(i == 0){
            for(char ch : {'R', 'G', 'B'}){
                getColumnStates(i+1, m, s + ch);
            }
        } else {
            for(char ch : {'R', 'G', 'B'}){
                if(s.back() != ch)
                    getColumnStates(i+1, m, s + ch);
            }
        }
    }

    bool isValid(const string &t, const string &s){
        for(int i=0; i<t.size(); i++){
            if(t[i] == s[i]) return false;
        }
        return true;
    }
    
    unordered_map<string, int> dp;
    int solve(const string &p, int i, int n){
        if(i == n) return 1;

        string key = p + "_" + to_string(i);

        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        int ans = 0;
        for(const string &t : prevStates){
            if(isValid(t, p)){
                ans = (ans + solve(t, i+1, n))%mod;
            }
        }

        return dp[key] = ans;
    }
public:
    int colorTheGrid(int m, int n) {
        string t = "";
        getColumnStates(0, m, t);

        int res = 0;
        for(const string &s : prevStates){
            res = (res + solve(s, 1, n))%mod;
        }

        return res;
    }
};