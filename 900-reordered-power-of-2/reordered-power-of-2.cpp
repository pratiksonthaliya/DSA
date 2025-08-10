class Solution {
private:
    bool isPowOf2(int idx, string &s){
        if(idx == s.size()){
            if(s[0] == '0') return 0;

            int n = stoi(s);
            //cout << n << " ";
            return !(n & (n-1));
        }

        bool isPow = false;
        for(int i=idx; i<s.size(); i++){
            swap(s[i], s[idx]);
            isPow |= isPowOf2(idx+1, s);
            swap(s[i], s[idx]);
        }   
        return isPow;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        return isPowOf2(0, s);
    }
};