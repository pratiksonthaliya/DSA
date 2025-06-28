class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> sortedNums;
        for(int i=0; i<nums.size(); i++){
            sortedNums.push_back({nums[i], i});
        }
        sort(sortedNums.rbegin(), sortedNums.rend());

        set<int> st; //idxs
        for(int i=0; i<k; i++){
            st.insert(sortedNums[i][1]);
        }

        vector<int> ans;
        for(int idx : st){
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};