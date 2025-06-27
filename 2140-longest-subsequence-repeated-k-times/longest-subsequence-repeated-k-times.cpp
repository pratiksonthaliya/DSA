class Solution {
private:
    bool isKRepeatedSubsequence(string& t, int k, string &s){
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
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        vector<char> candidate;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.push_back('a' + i);
            }
        }

        queue<string> q;
        for(char ch : candidate){
            q.push(string(1, ch));
        }

        string ans = "";
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr.size() > ans.size()){
                ans = curr;
            }

            for(char ch : candidate){
                string next = curr + ch;
                if(next.size() > ans.size() && isKRepeatedSubsequence(next, k, s)){
                    q.push(next);
                }
            }
        }

        return ans;
    }
};