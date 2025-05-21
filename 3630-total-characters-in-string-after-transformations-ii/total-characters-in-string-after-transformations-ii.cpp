class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<int>> matExp(vector<vector<int>> &T, int t){
        if(t == 0){
            vector<vector<int>> I(26, vector<int> (26, 0));
            for(int i=0; i<26; i++){
                I[i][i] = 1;
            }
            return I;
        }

        vector<vector<int>> mid = matExp(T, t/2);

        vector<vector<int>> res = matMultiply(mid, mid);
        if(t&1){
            res = matMultiply(res, T);
        }
        return res;
    }
    vector<vector<int>> matMultiply(vector<vector<int>> &A, vector<vector<int>> &B){
        vector<vector<int>> res(26, vector<int> (26, 0));
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                for(int k=0; k<26; k++){
                    res[i][j] = (res[i][j] + (A[i][k] * 1LL * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Calculate T
        vector<vector<int>> T(26, vector<int> (26, 0));
        for(int i=0; i<26; i++){
            for(int j=1; j<=nums[i]; j++){
                T[(i + j) % 26][i] = 1; // why??
            }
        }

        // Calculate T^t
        vector<vector<int>> res = matExp(T, t);

        vector<int> arr(26, 0);
        for(char &ch : s){
            arr[ch - 'a']++;
        }

        int ans = 0;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                ans = (ans + (arr[j] * 1LL * res[i][j])%MOD)%MOD; // why arr[i] ??
            }
        }

        return ans;
    }
};