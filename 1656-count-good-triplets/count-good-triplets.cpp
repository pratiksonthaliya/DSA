class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ct = 0, n = arr.size();
        vector<pair<int, int>> st; // i, j
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(arr[i] - arr[j]) <= a){
                    st.push_back({i, j});
                }
            }
        }

        for(auto p : st){ // i, j 
            int i = p.first;
            int j = p.second;
            for(int k=0; k<n; k++){
                if(k > i && k > j && abs(arr[i] - arr[k]) <= c && abs(arr[j] - arr[k]) <= b){
                    ct++;
                }
            }
        }

        return ct;
    }
};