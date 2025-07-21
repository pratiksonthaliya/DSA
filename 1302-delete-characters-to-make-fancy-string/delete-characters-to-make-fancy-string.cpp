class Solution {
public:
    string makeFancyString(string s) {

        string ans;

        int n=s.size(), i=0;
        while(i<n){

            char ch = s[i];
            int ct = 0;
            while(i<n && ch == s[i]){
                i++;
                ct++;
            }

            if(ct >= 3) ct = 2;
            while(ct--) ans += ch;
        }

        return ans;
    }
};