class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int &num : nums) mp[num]++;

        int maxVal = -1, maxFreq = 0;
        for(auto [num, freq] : mp){
            if(freq > maxFreq){
                maxVal = num;
                maxFreq = freq;
            }
        }

        int len = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maxVal){
                len++;
                if(2 * len > (i + 1) && 2 * (maxFreq - len) > n - (i + 1)){
                    return i;
                }
            }
        }

        return -1;
    }
};