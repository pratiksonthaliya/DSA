class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        for(string &s : folder){

            if(ans.empty()){
                ans.push_back(s);
            } else {
                string t = ans.back() + '/';
                if(s.substr(0, t.size()) != t){
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};