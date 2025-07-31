class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, prev;
        prev.insert(0);

        for(int x : arr){

            unordered_set<int> curr;
            curr.insert(x);
            for(int y : prev){
                curr.insert(x | y);
            }

            ans.insert(curr.begin(), curr.end());
            prev = curr;
        }

        return ans.size();
    }
};