class Solution {
public:
    int findLucky(vector<int>& arr) {

        for(int i=0; i<arr.size(); i++){
            int num = arr[i]%10000;
            if(num <= arr.size())
                arr[num - 1] += 10000;
            
            // for(int j=0; j<arr.size(); j++){
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
        }

        int ans = -1;
        for(int i=0; i<arr.size(); i++){
            cout << (i+1) << " " << arr[i]/10000 << endl;
            if(arr[i]/10000 == (i+1)){
                ans = max(ans, i+1);
            }
        }

        return ans;
    }
};