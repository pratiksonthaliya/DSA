class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> st(nums.begin(), nums.end());

        for(int i=0; i<=(1<<n); i++){

            cout << i << " ";

            string s(n, '0');

            int num = i;
            for(int j=n-1; j>=0; j--){
                if(num & (1<<j)) s[j] = '1';
            }

            cout << s << endl;

            if(!st.count(s)) return s;
        }
        return "";
    }
};