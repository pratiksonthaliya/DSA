class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &num : nums){
            mp[num]++;
        }

        for(auto [num, freq] : mp){
            if((freq&1) == 1){
                return false;
            }
        }

        return true;
    }
};