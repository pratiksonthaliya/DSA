class Solution {
public:
    int longestSubsequence(string s, int k) {

        long int num = 0, i = s.size()-1, j = 0;

        int ct = 0;
        while(i >= 0 && (num|(1<<j)) <= k){
            if(s[i] == '1'){
                num |= (1<<j);
            }
            i--; j++; ct++;
        }

        for(int j=i; j>=0; j--){
            if(s[j] == '0') ct++;
        }

        return ct;
    }
};