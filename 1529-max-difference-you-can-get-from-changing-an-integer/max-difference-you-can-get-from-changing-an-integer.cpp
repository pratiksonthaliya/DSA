class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();

        unordered_set<char> st(s.begin(), s.end());
        if(st.size() == 1){
            for(int i=0; i<s.size(); i++){
                s[i] = '8';
            }
            return stoi(s);
        }
        
        // Maxi
        string maxi = s;
        char ch = '#';
        for(int i=0; i<n; i++){
            if(maxi[i] < '9' && ch == '#'){
                ch = maxi[i];
            }

            if(maxi[i] == ch){
                maxi[i] = '9';
            }
        }

        // Mini
        string mini = s;
        if(s[0] == '1'){
            ch = '#';
            for(int i=1; i<n; i++){
                if(mini[i] > '1' && ch == '#'){
                    ch = mini[i];
                }

                if(mini[i] == ch){
                    mini[i] = '0';
                }
            }
        } else {
            ch = '#';
            for(int i=0; i<n; i++){
                if(mini[i] > '1' && ch == '#'){
                    ch = mini[i];
                }

                if(mini[i] == ch){
                    mini[i] = '1';
                }
            }
        }

        cout << maxi << " " << mini;

        return stoi(maxi) - stoi(mini);
    }
};