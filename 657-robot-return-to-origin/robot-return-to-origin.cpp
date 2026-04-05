class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char &ch : moves){
            y = y + (ch == 'U') - (ch == 'D');
            x = x + (ch == 'R') - (ch == 'L');
        }
        return (x==0 && y==0);
    }
};