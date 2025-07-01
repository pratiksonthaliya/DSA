class Solution {
public:
    int possibleStringCount(string word) {
        
        int ct = 0, freq = 0;
        int i = 0, j = 0, n = word.size();
        while(i < n && j < n){
            while(j < n && word[i] == word[j]){
                j++;
            }

            //cout << i << " " << j << endl;

            if(j - i > 1){
                ct++;
                freq += (j - i);
            }

            i = j;
        }

        if(ct == 0) return 1;
        return freq - (ct - 1);
    }
};