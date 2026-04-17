class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans, i - mp[nums[i]]);
            }

            int rev = 0;
            while(nums[i]){
                rev = rev*10 + (nums[i]%10);
                nums[i] /= 10;
            }
            mp[rev] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};