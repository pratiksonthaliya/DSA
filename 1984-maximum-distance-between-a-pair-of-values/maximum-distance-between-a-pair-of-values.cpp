class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, j = nums2.size() - 1;
        for(int i=nums1.size()-1; i>=0; i--){
            while(j >= 0 && nums1[i] > nums2[j]) j--;
            if(i <= j && nums1[i] <= nums2[j]) ans = max(ans, j-i);
        }
        return ans;
    }
};