class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string s = countAndSay(n-1);
        string ans;

        for(int i=0; i<s.size(); i++){
            int j = i;
            while(j<s.size() && s[j] == s[i]) j++;

            ans += to_string(j-i);
            ans += s[i];

            i = j-1;
        }

        return ans;
    }
};