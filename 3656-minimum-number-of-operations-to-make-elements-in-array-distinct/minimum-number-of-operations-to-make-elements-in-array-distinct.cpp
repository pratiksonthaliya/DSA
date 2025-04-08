class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i+=3){
            bool isAns = true;
            unordered_set<int> st;
            for(int j=i; j<n; j++){
                if(st.count(nums[j]) > 0){
                    isAns = false;
                }
                st.insert(nums[j]);
            }

            if(isAns){
                return i/3;
            }
        }

        return (n + 2) / 3;
    }
};