class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == INT_MIN) return false;
        return !(n&(n-1)) && (n-1)%3==0;
    }
};