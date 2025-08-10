class Solution {
private:
    bool isPowOf2(string &s, string &t, vector<int> &vis){
        if(t.size() == s.size()){
            if(t[0] == '0') return 0;

            int n = stoi(t);
            //cout << n << " ";
            return !(n & (n-1));
        }

        bool isPow = false;
        for(int i=0; i<s.size(); i++){
            if(vis[i]) continue;

            vis[i] = 1;
            t.push_back(s[i]);

            isPow |= isPowOf2(s, t, vis);

            t.pop_back();
            vis[i] = 0;
        } 
        return isPow;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        string t;
        vector<int> vis(s.size()+1, 0);
        
        return isPowOf2(s, t, vis);
    }
};