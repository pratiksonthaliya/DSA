class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return 0;

        double x = 1.0*log10(n)/log10(3);
        // cout << 1.0*log(n)/log(3) << " " << (int) (1.0*log(n)/log(3)) << endl;
        cout << x << " " << int(x) << endl;

        return (x == (int) x);

        return abs((log(n) + log(3) - 1)/log(3) - log(n)/log(3)) < 1;
    }
};