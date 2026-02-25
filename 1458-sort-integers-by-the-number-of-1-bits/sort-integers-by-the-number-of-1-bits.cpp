class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &a, int &b){
            int k1 = __builtin_popcount(a), k2 = __builtin_popcount(b);
            return (k1 != k2 ? (k1 < k2) : (a < b));
        });
        return arr;
    }
};