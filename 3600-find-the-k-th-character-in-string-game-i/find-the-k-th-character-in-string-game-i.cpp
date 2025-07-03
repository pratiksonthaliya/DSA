class Solution {
public:
    char kthCharacter(int k) {
        string s = string(1, 'a');

        while(s.size() < k){
            string t;
            for(char ch : s){
                t += ((ch - 'a' + 1)%26 + 'a');
            }
            s += t;
        }    

        return s[k-1];
    }
};