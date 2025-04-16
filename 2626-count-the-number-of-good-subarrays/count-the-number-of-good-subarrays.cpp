class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;

        int i=0, j=0, n=nums.size(), z = k;
        unordered_map<int, int> mp;
        while(j < n){
            mp[nums[j]]++;
            z -= (mp[nums[j]] - 1); // (mp[nums[j]] * (mp[nums[j]] - 1) / 2);

            cout << z << " ";

            // if(z == 0){
            //     ans += (n - j);
            // }

            while(i<n && z <= 0){
                if(z <= 0) ans += (n-j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                else z += mp[nums[i]];
                i++;
            }

            j++;
        }

        return ans;
    }
};