class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int a = 0;
        vector<int> pre_b(n, 0), pre_a(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] == 'a') a++;
            pre_b[i] = (i==0 ? 0 : pre_b[i-1]) + (s[i] == 'b');
            pre_a[i] = (i==0 ? 0 : pre_a[i-1]) + (s[i] == 'a');
        }

        int ans = n;
        for(int i=0; i<n; i++){
            ans = min(ans, (i==0 ? 0 : pre_b[i-1]) + (a - pre_a[i]));
        }
        return ans;
    }
};