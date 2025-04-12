class Solution {
private:
    unordered_set<string> palins;
    void getKPalindrome(int n, int k){
        int d = (n+1)/2;

        int st = pow(10, d-1);
        int en = pow(10, d) - 1;

        for(int num = st; num <= en; num++){
            string t = to_string(num);
            string r = t;
            if((n&1)){
                r.pop_back();
            }
            reverse(r.begin(), r.end());

            t += r;
            if(stoll(t)%k == 0){
                sort(t.begin(), t.end());
                palins.insert(t);
            }
        }
    } 
public:
    long long countGoodIntegers(int n, int k) {
        getKPalindrome(n, k);    

        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        for (const string &s : palins) {
            vector<int> cnt(10);
            for (char c : s) {
                cnt[c - '0']++;
            }
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt) {
                tot /= factorial[x];
            }
            ans += tot;
        }

        return ans;
    }
};