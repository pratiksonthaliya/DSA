class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> arr(32, 0);
        for(int &num : nums){
            for(int i=0; i<32; i++){
                arr[i] += (1&(num>>i));
            }
        }

        int ans = 0;
        for(int i=0; i<32; i++){
            if(arr[i]%3 != 0)
                ans += (1<<i);
        }

        for(int i : arr){
            cout << i << " ";
        }
        return ans;
    }
};