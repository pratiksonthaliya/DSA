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

        vector<string> keys = {"ab", "ba"};
        if(y > x){
            swap(x, y);
            swap(keys[0], keys[1]);
        }

        ans += x*countAndRemove(keys[0], s);
        ans += y*countAndRemove(keys[1], s);
        
        return ans;
    }
};