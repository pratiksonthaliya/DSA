class Solution {
public:
    bool isValid(string word) {
        
        bool hasV = false, hasC = false;
        int ct = 0;

        for(char ch : word){
            if(tolower(ch) >= 'a' && tolower(ch) <= 'z'){
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') hasV = 1;
                else hasC = 1;
                ct++;
            }
            else if(ch >= '0' && ch <= '9') ct++;
            else return 0;
        }
        
        return (hasV && hasC && ct >= 3);
    }
};