class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) return false;

        int n = s.size();
        for(int i=0; i<n; i++){
            bool isAns = true;
            for(int j=0; j<n; j++){
                if(goal[j] != s[(i+j+n)%n]){
                    isAns = false;
                    break;
                }
            }
            if(isAns) return true;
        }
        return false;
    }
};