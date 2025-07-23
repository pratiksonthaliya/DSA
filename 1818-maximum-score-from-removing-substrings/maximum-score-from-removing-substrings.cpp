class Solution {
private:
    int countAndRemove(const string &k, string &s){
        string t;
        int ct = 0;
        for(char ch : s){
            if(!t.empty() && (t.back() == k[0] && ch == k[1])){
                ct++;
                t.pop_back();
            } else {
                t.push_back(ch);
            }
        }
        s = t;
        return ct;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x >= y){
            ans += x*countAndRemove("ab", s);
            ans += y*countAndRemove("ba", s);
        } else if(y > x){
            ans += y*countAndRemove("ba", s);
            ans += x*countAndRemove("ab", s);
        }
        return ans;
    }
};