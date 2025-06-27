class Solution {
private:   
    string s, ans;
    bool isKRepeatedSubsequence(string& t, int k){
        int i = 0;
        for(char ch : s){
            if(ch == t[i]){
                i++;
                if(i == t.size()){
                    i = 0;
                    k--;
                    if(k == 0) return 1;
                }
            }
        }

        return 0;
    }
    void findSubsequence(vector<int>& mp, string t, int k){
        if(t.size()*k > s.size()){
            return;
        }

        for(int i=25; i>=0; i--){
            if(mp[i] > 0){                
                mp[i]--;
                t += (i + 'a');

                if(isKRepeatedSubsequence(t, k)){
                    if(ans.size() < t.size()){
                        ans = t;
                    }
                    findSubsequence(mp, t, k);
                }

                mp[i]++;
                t.pop_back();
            }
        }

    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        this->s = s;
        
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<int> mp(26, 0);
        for(int i=25; i>=0; i--){
            if(freq[i] >= k){
                mp[i] = freq[i]/k;
            }
        }

        string t = "";
        findSubsequence(mp, t, k);
        return ans;
    }
};