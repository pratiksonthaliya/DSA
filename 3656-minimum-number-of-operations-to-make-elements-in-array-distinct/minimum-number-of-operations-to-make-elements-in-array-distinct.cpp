class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> st;
        for(int i=n-1; i>=0; i--){
            if(st.count(nums[i]) > 0){
                return (i + 3) / 3;
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};