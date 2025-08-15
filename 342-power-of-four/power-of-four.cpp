class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;
        double k = log10(n) / log10(4);
        return k == (int) k;
    }
};