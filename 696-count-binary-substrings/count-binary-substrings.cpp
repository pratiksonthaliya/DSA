class Solution {
public:
    int countBinarySubstrings(string s) {
        char pch = s[0];
        int pct = 0, ct = 0, ans = 0;

        for(char &ch : s){

            if(ch == pch){
                ct++;
            } else {
                ans += min(pct, ct);

                pct = ct;
                ct = 1;
                pch = ch;
            }
        }

        ans += min(pct, ct);
        return ans;
    }
};