class Solution {
private:
    vector<long> mergeSort(int l, int r, int &ans, vector<int>& arr){
        if(l > r)  return {};
        if(l == r) return {arr[l]};
        
        int mid = (l + r)/2;
        
        vector<long> left  = mergeSort(l, mid, ans, arr);
        vector<long> right = mergeSort(mid + 1, r, ans, arr);
        
        int i=0, j=0, n = left.size(), m = right.size();

        int ct = 0;
        for(long val : right){
            auto it = upper_bound(left.begin(), left.end(), 2*val);
            if(it != left.end()){
                ct += n - (it - left.begin());
            }
        }
        
        // int ct = 0;
        vector<long> merged;
        while(i < n && j < m){
            
            if(left[i] <= right[j]){
                merged.push_back(left[i]);
                i++;
            } else {
                // ct += (n - i);
                merged.push_back(right[j]);
                j++;
            }
        }
        
        while(i < n){
            merged.push_back(left[i]);
            i++;
        }
        
        while(j < m){
            merged.push_back(right[j]);
            j++;
        }
        
        ans += ct;
        return merged;
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(0, nums.size() - 1, ans, nums);
        return ans;
    }
};