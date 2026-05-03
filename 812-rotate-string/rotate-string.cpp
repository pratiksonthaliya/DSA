class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) return false;

        int n = s.size();
        for(int i=0; i<n; i++){
            bool isAns = true;
            cout << i << " -> ";
            for(int j=0; j<n; j++){
                //cout << (i+j+n)%n << " ";
                if(goal[j] != s[(i+j+n)%n]){
                    isAns = false;
                    break;
                }
            }
            // cout << endl;
            if(isAns) return true;
        }
        return false;
    }
};