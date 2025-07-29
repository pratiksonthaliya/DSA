class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return {1};

        vector<int> max_or(n);
        max_or[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            max_or[i] = max_or[i+1] | nums[i];
        }

        for(int orr : max_or){
            cout << orr << " ";
        }
        cout << endl;

        vector<int> bits(32, 0);

        int j = 0, val = 0;
        vector<int> ans(n, 1);
        for(int i=0; i<n; i++){
            while(j<n && val != max_or[i]){
                val |= nums[j];
                for(int k=0; k<32; k++){
                    bits[k] += ((nums[j]>>k)&1);
                }
                j++;
            }

            ans[i] = max(ans[i], j-i);

            // ans.push_back(j - i);
            for(int k=0; k<31; k++){
                bits[k] -= ((nums[i]>>k)&1);
                if(bits[k] == 0 && ((nums[i]>>k)&1)){
                    val ^= (1<<k);
                }
            }
        }

        return ans;
    }
};