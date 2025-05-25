class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if(n == 0 || s[0] == '0') return 0;

        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int i=1; i<n; i++){
            int one = (s[i] - '0');
            int two = stoi(s.substr(i-1, 2));

            if(one > 0 && one < 10){
                dp[i+1] += dp[i];
            }

            if(two > 9 && two < 27 ){
                dp[i+1] += dp[i-1];
            }
        }
        
        return dp[n];
    }
};