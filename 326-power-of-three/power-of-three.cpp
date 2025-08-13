class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return 0;

        long int num = 1;
        while(num <= n){
            if(num == n) return 1;
            num = num * 3;
        }
        return 0;
    }
};