class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        for(int i=0, ct=-(n/2); i<n; i++, ct++){
            if(!(n&1) && i == n/2) ct++;
            arr.push_back(ct);
        }
        return arr;
    }
};