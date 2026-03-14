class Solution {
private:
    string ans;
    void getString(string &s, int n, int &k){
        if(s.size() == n){
            k--;
            if(k == 0) ans = s; 
            return;
        }

        if(k < 0) return;

        for(char ch : {'a', 'b', 'c'}){
            if(s.empty() || s.back() != ch){
                s.push_back(ch);
                getString(s, n, k);
                s.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {

        if(k > 3 * (1<<(n-1))) return "";

        string s;
        getString(s, n, k);
        return ans;
    }
};