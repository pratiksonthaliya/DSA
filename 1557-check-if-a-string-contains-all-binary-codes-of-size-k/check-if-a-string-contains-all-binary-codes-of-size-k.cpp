class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int ct = 0;
        vector<bool> seen((1<<k), 0);

        for(int i=k-1; i<s.size(); i++){
            int val = stoi(s.substr(i-k+1, k), nullptr, 2);

            if(!seen[val]){
                seen[val] = 1;
                ct++;
            }
        }
        return (ct == (1<<k));
    }
};