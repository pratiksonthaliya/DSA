class Solution {
public:
    int longestSubsequence(string s, int k) {

        long num = 0, j = 0, ct = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == '1'){
                if(j <= 30 && (num|(1<<j)) <= k){
                    num |= (1<<j);
                    ct++;
                }
            } else {
                ct++;
            }
            j++;
        }

        return ct;
    }
};