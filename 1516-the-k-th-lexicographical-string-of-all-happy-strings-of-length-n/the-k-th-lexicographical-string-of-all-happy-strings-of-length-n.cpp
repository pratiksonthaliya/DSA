class Solution {
private:
    int N;
    vector<string> strs;
    void makeStrings(string &s){
        if(s.size() == N){
            strs.push_back(s);
            return;
        }

        for(char ch : {'a', 'b', 'c'}){
            if(s.empty() || s.back() != ch){
                s.push_back(ch);
                makeStrings(s);
                s.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        N = n;
        // 3 ^ 2 ^ 2 ^ 2

        if(k > 3 * (1<<(n-1))) return "";

        string s;
        makeStrings(s);

        // sort(strs.begin(), strs.end());
        return strs[k-1];
    }
};