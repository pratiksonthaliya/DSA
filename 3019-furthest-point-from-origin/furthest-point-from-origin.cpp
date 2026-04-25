class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int p = 0, ct = 0;
        for(char &ch : moves){
            if(ch == 'R') p++;
            else if(ch == 'L') p--;
            else ct++;
        }
        return abs(p) + ct;
    }
};