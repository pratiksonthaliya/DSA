class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        long int num = 1;
        while(num < INT_MAX){
            string t = to_string(num);
            sort(t.begin(), t.end());

            if(t == s) return 1;
            num = num * 2;
        }

        return 0;
    }
};