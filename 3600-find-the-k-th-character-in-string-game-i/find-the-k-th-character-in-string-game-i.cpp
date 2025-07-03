class Solution {
public:
    char kthCharacter(int k) {
        int ct = __builtin_popcount(k-1);
        return 'a' + ct%26;
    }
};