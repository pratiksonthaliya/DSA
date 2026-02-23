class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        for(int i=k-1; i<s.size(); i++){
            st.insert(s.substr(i-k+1, k));
        }

        return (st.size() == (1<<k));
    }
};