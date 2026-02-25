class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &a, int &b){
            int k1 = __builtin_popcount(a);
            int k2 = __builtin_popcount(b);

            if(k1 != k2) return k1 < k2;
            else return a < b;
        });

        return arr;
    }
};