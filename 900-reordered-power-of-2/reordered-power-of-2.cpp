class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long int num = 1;
        unordered_set<string> pows;
        while(num < INT_MAX){
            string t = to_string(num);
            sort(t.begin(), t.end());
            pows.insert(t);
            num = num * 2;
        }

        string s = to_string(n);
        sort(s.begin(), s.end());
        return pows.count(s);
    }
};