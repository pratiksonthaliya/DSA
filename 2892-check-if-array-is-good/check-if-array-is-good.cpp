class Solution {
public:
    bool isGood(vector<int>& nums) {

        map<int, int> mp;
        // for(int i=0; i<nums.size(); i++){

        // }
        for(int i=0; i<nums.size(); i++){
            
            int k = (i==0 ? nums.size() - 1 : i);

            mp[k]--;
            mp[nums[i]]++;
            if(mp[k] == 0) mp.erase(i);
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            // ans ^= i;
        }
        return (mp.size() == 0);
    }
};