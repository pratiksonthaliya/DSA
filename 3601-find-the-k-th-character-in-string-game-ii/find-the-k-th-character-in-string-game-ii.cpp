class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int idx;

        while(k != 1){
            idx = log2(k);
            if((1LL<<idx) == k){
                idx--;
            }
            k = k - (1LL<<idx);

            if(operations[idx]){
                ans++;
            }
        }

        return 'a' + ans%26;
    }
};