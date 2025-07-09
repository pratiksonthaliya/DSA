class Solution {
private:
    unordered_set<string> st = {"electronics", "grocery", "pharmacy", "restaurant"};
    bool isValid(string &s){
        for(char ch : s){
            if(!(isalnum(ch) || ch == '_')) return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<pair<string, string>> arr;
        for(int i=0; i<n; i++){
            if(!isActive[i] || !st.count(businessLine[i]) || code[i].empty() || !isValid(code[i])) continue;
            arr.push_back({businessLine[i], code[i]});
        }
        sort(arr.begin(), arr.end());

        vector<string> ans;
        for(auto x : arr) ans.push_back(x.second);
        return ans;
    }
};