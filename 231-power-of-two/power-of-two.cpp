class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long N = n;
        if(N == 0) return 0;
        return !(N & (N-1));
    }
};