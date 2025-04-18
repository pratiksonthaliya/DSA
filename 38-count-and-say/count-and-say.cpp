class Solution {
public:
    string countAndSay(int n) {
        // if(n == 1) return "1";
        
        string ans = "1";
        for(int i=1; i<n; i++){
            string t;
            for(int i=0; i<ans.size(); i++){
                int j = i;
                while(j<ans.size() && ans[j] == ans[i]) j++;

                t += to_string(j-i);
                t += ans[i];

                i = j-1;
            }
            ans = t;
        }

        return ans;
    }
};