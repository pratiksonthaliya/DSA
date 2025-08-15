class Solution {
public:
    bool isPowerOfFour(long int n) {

        return !(n&(n-1)) && (n-1)%3==0;
    }
};