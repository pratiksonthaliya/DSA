class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int, int> freq2; //arr2: {val, freq}
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        
        for(int val : arr2){
            freq2[val]++;
        }
    }
    
    void add(int index, int val) {
        int prev_val = arr2[index];
        int new_val  = prev_val + val;

        freq2[prev_val]--;
        freq2[new_val]++;

        arr2[index] = new_val;
    }
    
    int count(int tot) {
        int ct = 0;
        for(int val : arr1){
            if(freq2.count(tot - val) > 0){
                ct += freq2[tot - val];
            }    
        }
        return ct;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */