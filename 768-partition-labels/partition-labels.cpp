class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        vector<int> curr(26, 0);
        vector<int> ans;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            curr[s[i] - 'a']++;

            bool flag = true;
            for(int j=0; j<26; j++){
                if(curr[j] > 0 && curr[j] != freq[j]){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(i + 1 - start);
                start = i+1;
                curr = vector<int> (26, 0);
            }
        }

        return ans;
    }
};