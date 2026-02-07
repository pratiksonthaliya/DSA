class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> pre_b(n, 0), suf_a(n, 0);
        for(int i=0; i<n; i++){
            pre_b[i] = (i==0 ? 0 : pre_b[i-1]) + (s[i] == 'b');
        }

        for(int i=n-1; i>=0; i--){
            suf_a[i] = (i==n-1 ? 0 : suf_a[i+1]) + (s[i] == 'a');
        }

        int ans = n;
        for(int i=0; i<n; i++){
            ans = min(ans, (i==0 ? 0 : pre_b[i-1]) + (i==n-1 ? 0 : suf_a[i+1]));
        }
        return ans;
    }
};